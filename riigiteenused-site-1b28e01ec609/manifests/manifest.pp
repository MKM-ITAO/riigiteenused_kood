class { 'systools': }
class { 'apache': }
class { 'php':
  development => true
}

class { 'drush': }
class { 'postfix': }


class { 'mysql':
  local_only     => true,
  hostname => $fqdn
}

apache::vhost { "drupal": 
    document_root => $drupal_root
}
