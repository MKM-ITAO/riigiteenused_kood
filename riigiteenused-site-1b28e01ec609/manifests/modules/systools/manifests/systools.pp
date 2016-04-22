class systools (
  $packages = [
    'puppet-el',
    'htop',
    'git-core',
    'curl',
    'aptitude',
    'zip',
    'gzip',
    'vim'
  ]
) {
  package { $packages:
    ensure => latest,
  }
  exec { 'apt-get update':
    command => "/usr/bin/apt-get update"
  }
  Package { require => Exec['apt-get update'] }
}
