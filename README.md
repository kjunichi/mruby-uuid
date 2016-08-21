# mruby-uuid   [![Build Status](https://travis-ci.org/kjunichi/mruby-uuid.svg?branch=master)](https://travis-ci.org/kjunichi/mruby-uuid)
Uuid class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'kjunichi/mruby-uuid'
end
```
## example
```ruby
p Uuid.uuid
#=> "f557e3a6-c3a8-4862-8e13-1d17f2d3e87e"
```

## License
under the MIT License:
- see LICENSE file
