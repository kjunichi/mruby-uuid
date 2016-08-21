MRuby::Gem::Specification.new('mruby-uuid') do |spec|
  spec.license = 'MIT'
  spec.authors = '@kjunichi'

  ossp_uuid_cflg = `uuid-config --cflags`.chomp!
  spec.cc.flags << ossp_uuid_cflg

  ossp_uuid_libs = `uuid-config --ldflags --libs`.chomp!
  spec.linker.flags_before_libraries << ossp_uuid_libs
end
