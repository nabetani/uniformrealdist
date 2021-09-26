require "fileutils"

def test(cpp, cc, name)
  return if %x(which #{cc}).strip.empty?
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
  (7..11).each do |v|
    test( cpp, "g++-#{v}", "gcc#{v}" )
  end
end
