
#Pipe that we write into which chess engine reads
@pipe1 = open("/tmp/chessPipe", "w+")
#Pipe to read from where chess engine writes
@pipe2 = open("/tmp/chPipe", "r+")

def getMoves
  @pipe1.puts "show moves"
  @pipe1.flush

  input =  ""
  begin
    line = @pipe2.gets
    puts "dbg: #{line}"
    input += line
  end while !line.include? "END"

  input.split("START").last.delete("END")
end

#Makes a move and gets CPU's response
def makeMove mv
  @pipe1.puts mv 
  @pipe1.flush

  input =  ""
  begin
    line = @pipe2.gets
    input += line
  end while !line.include? ">\n"

  input.split("<").last.delete(">")
end

while(true)
  #Get all possible moves
  moves = getMoves

  puts "Possible moves: #{moves}"

  mv = gets

  cpuMv = makeMove mv
  puts "Return move #{cpuMv} \n"
end
