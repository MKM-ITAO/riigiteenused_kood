Teenuste kataloog rakendus
======

Development environment
======
### Getting started with local dev environment
1. Create /srv/www (locally)
> mkdir /srv/www  
cd /srv/www  
2. Clone site structure from repo
> git clone git@bitbucket.org:mekaia/riigiteenused-site.git -b dev riigiteenused-site
3. Create Vagrant environment 
> vagrant up  
vagrant ssh 
4. Inside Vagrant box  
   Create database (if you have not done that before)
> mysqladmin -uroot -ppassword create riigiteenused_db  

5. Exit vagrant
> vagrant exit

6. Build the site _(outside of Vagrant box)_
_This will run site make and other tasks needed to setup the site correct, like cloning the profile. This should be done outside the vagrant box, in the riigiteenused-site folder._  
> ./build

7. Install the site  
> vagrant ssh  
cd /srv/www/riigiteenused-site/web  
drush si riigiteenused --account-name=adminkasutaja --account-pass=3vmotu8 --db-url=mysql://root:password@localhost/riigiteenused_db -y -v --locale=et

_*riigiteenused* used as DB username/password/name on MKM test server._
> drush si riigiteenused --account-name=adminkasutaja --account-pass=3vmotu8 --db-url=mysql://riigiteenused:riigiteenused@192.168.4.19/riigiteenused -y -v --locale=et

### Accessing the environment
Add the following to your (local) hosts file  
> 192.168.50.93   riigiteenused.dev  

The ip address is defined in the Vagrantfile  

### After installation
  Create Web portal menu block on the fresh site install.  
  GO: admin/structure/block/add-menu-block  
  Block title: <none>  
  Menu: Web portal  
  Maximum depth: 2  
  CSS class: block-web-portal-navigation-menu (should save block before input appears)  
  Valitsusportaal (default theme): Portal Navigation First  

## Working with profiles
### Adding modules 
All new modules goes into the .make (riigiteenused.make) file in the profile.  
You need to specify an exact version of the module (so that builds are consistent).  

### Enable modules 
Enabling modules is done in 2 ways.   
For modules needed to develop features, you simply add them as dependencies in the relevant features.  

For general modules that don't really depend on anything special you add it to the .info file. (riigiteenused.info)

***

API
======
## URLS
### Services list request URL  
> /api/%language%/all

### Ministry services list request URL  
> /api/%language%/all/%ministry/institution name%

### Service's detail request URL
> /api/%language%/single/%uuid%

### Private API > all services
> /api/%language%/private

### Private API > ministry / institution services
> /api/%language%/private/%ministry/institution name%

### Taxonomies API  
> /export/terms  

***

Installation workflow in VP application
======
## Server requirements  
1. [Drupal system requirements](https://www.drupal.org/requirements)
2. [PHP configuration](https://www.drupal.org/requirements/php)  
    * PHP memory limit 256 Mb  
3. APC  
4. Memcache  
    4. Install and configure memcache: [Memcache installation](https://www.drupal.org/node/1131468), [Configuring memcache (server, drupal)](https://www.thefanclub.co.za/how-to/how-install-memcached-on-ubuntu-for-drupal).     
    4. Install [Entity cache](https://www.drupal.org/project/entitycache) and [Memcache API and Integration](https://www.drupal.org/project/memcache) modules.  
    4. Check _admin/reports/status_ for memcache status.  

## Riititeenused package
### Package installation
1. Create directory in VP modules directory _profiles/vp_profile/modules/riigiteenused_. 
2. Copy following modules and files from riigiteenused application:  
    * features/taxonomies  
    * features/teenus  
    * features/services_search  
    * custom/rt_teenus_importer
3. Check for unmet dependencies of contrib modules and install them!
4. Enable riigiteenused packages modules.   
5. Update **views** module to latest version!  

### Configuring modules 
Configuration page: admin/config/teenus_application_configuration
 

### Adding menu points
#### Create menu node  
1. Go to node/add/vp-menu-dropdown-box.  
2. Add node with parameters:  
    _Title_: Haldusala teenused  
    _Body (this is a example, HTML might be different for each VP application)_:    
    
```
#!html

<div class="static static-mainmenu-popup">
  <div class="mainmenu-popup-content">
    <div class="container-12 has-big-column-separators">
      <div class="column grid-4">
        <div class="grid-inner">
          <h2 class="bigger">Ministeerium ja kontaktid</h2>
          <div class="widget-text gray">
            <p>Majandus- ja Kommunikatsiooniministeeriumi eesmärk on riigi majanduspoliitika väljatöötamise, elluviimise ja tulemuste hindamise kaudu luua tingimused Eesti majanduse konkurentsivõime kasvuks ning tasakaalustatud ja jätkusuutlikuks arenguks.</p>
            <p><img alt="Majandus- ja Kommunikatsiooniministeeriumi maja plaat" height="120px" src="/sites/default/files/content-editors/Fotod/mkm_plaat_cropped.jpg" width="260px"></p>
          </div>
        </div>
      </div>
      <div class="column grid-5">
        <div class="grid-inner">
          <h2>Lingid</h2>
          <ul class="widget-menu">
            <li><a href="/teenuste-otsing">Teenuste otsing</a></li>
            <li><a href="/statistika/ministeerium">Numbrid</a></li>
            <li><a href="/statistika/valitsus">Kõik teenused</a></li>
          </ul>
        </div>
      </div>
    </div>
  </div>
</div>
<p>&nbsp;</p>
```  
3. __Set node to published.__  

    
#### Configure menu point for that node
> Main menu  
weight: -47  

#### Link should be visible now in main menu

#### Add sub-links for "Haldusala teenused" menu point
1. Go to admin/structure/menu/manage/main-menu.  
2. Add required links under "Haldusala teenused" menu point.    
> Example:  
Teenuste otsing > teenuste-otsing  
Numbrid > statistika/ministeerium  
Kõik teenused > statistika/valitsus  

3. Set up weights.  
    
#### Create additional block menu to display second lvl links   
GO: admin/structure/block/add-menu-block  
Block title: <none>  
Menu: Main menu (Peamenüü)   
Starting level: 2  
Maximum depth: 3  
CSS class: block-main-menu-sub-rt-menu (should save block before input appears)  
Valitsusportaal (default theme): Top (Ülesse)  

**Configure visibility of this menu block under "Show block on specific pages"!**  
This menu block should be visible only on pages created in previous chapter: _Add sub-links for "Haldusala teenused" menu point_
> Example (remove space in the end of each line):  
teenuste-otsing/*  
statistika/*  

#### Configure page title blocks visibility
GO: admin/structure/block/manage/delta_blocks/page-title/configure  
Add same configuration like in previous step:  
> Example (remove space in the end of each line):  
teenuste-otsing/*  
statistika/*

#### Import / Synchronize services from Riigiteenused application's API
_Will also synchronize taxonomies._  
Goto:  
> importer/teenused

Click "Synchronize services and taxonomies" > Services and taxonomies should be imported.  

#### Check views caching is enabled!  

#### Configure content permissions  
1. Recall "Bypass content access control", "Administer content types" and "Administer content" permissions from "content editor" and "administrator" user roles.    
This will prevent any user (except admin) from adding / editing Teenus nodes.  
2. Exclude Teenus nodes being displayed in content view  
Goto: _admin/structure/views/view/admin_views_node/edit_  
Add filter _Content: Type (<> Teenus)_    

***

Misc
======
## Helper scripts
1. Regular build from riigiteenused-site repo
> ./build  
2. Update riigiteesed profile on RIA Test
> ./update_riigiteenused_test