pipe1 = open("/tmp/chessPipe", "w+")
  pipe1.puts "show moves\n"
  pipe1.flush

pipe2 = open("/tmp/chPipe", "r+")
input =  ""
begin 
  line = pipe2.gets
  input += line
end while !line.eql? "END\n"

input = input.split("START").last.delete("END")

puts "Possible moves: #{input}"

#pipe = open("/tmp/chessPipe", "w+")
  pipe1.puts "a2a4\n"
  pipe1.flush

 
#pipe = open("/tmp/chPipe", "r+")
input =  ""
begin
  line = pipe2.gets
  input += line
end while !line.include? ">\n"

input = input.split("<").last.delete(">")
puts "Return move #{input} \n"




#pipe = open("/tmp/chessPipe", "w+")
#  pipe.flush
  #pipe.puts "show moves"
  #pipe.flush

#pipe = open("/tmp/chPipe", "r+")
#counter = 1
#input =  ""

#begin
  #line = pipe.gets
  #input += line
#end while !line.eql? "END\n"

#puts input


