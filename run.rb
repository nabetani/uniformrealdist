require "fileutils"

def test(cpp, cc, name)
  dir = "bin/"+name
  FileUtils.mkdir_p(dir)
  Dir.chdir(dir) do
    puts("#{name}: " + %x(#{cc} -Wall -O2 -std=c++11 ../../#{cpp} && ./a.out))
  end
end

cpp = ARGV[0] || "main.cpp"
puts cpp
Dir.chdir( File.split(__FILE__).first ) do
  test( cpp, "clang++", "clang" )
  test( cpp, "g++-11", "gcc11" )
  test( cpp, "g++-7", "gcc7" )
end
