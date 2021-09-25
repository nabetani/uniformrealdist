require "fileutils"

def test(cc,name)
  dir = "bin/"+name
  FileUtils.mkdir_p(dir)
  Dir.chdir(dir) do
    puts("#{name}: " + %x(#{cc} -Wall -O2 -std=c++11 ../../main.cpp && ./a.out))
    p $?
  end
end

Dir.chdir( File.split(__FILE__).first ) do
  test( "clang++", "clang" )
  test( "g++-11", "gcc11" )
  test( "g++-7", "gcc7" )
end
