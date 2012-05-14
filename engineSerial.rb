require 'rubygems'
require 'serialport'
#
#Pipe that we write into which chess engine reads
@pipe1 = open("/tmp/chessPipe", "w+")
#Pipe to read from where chess engine writes
@pipe2 = open("/tmp/chPipe", "r+")

#Set up serial ports
sp1 = "/dev/ttyACM0"
sp2 = "/dev/ttyACM1"
baud = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE

@spR = SerialPort.new(sp1, baud, data_bits, stop_bits, parity)
@spW = SerialPort.new(sp2, baud)

#Get moves for a specific square
def getMoves square
  @pipe1.puts "show moves"
  @pipe1.flush

  input =  ""
  begin
    line = @pipe2.gets
    input += line
  end while !line.include? "END"

  #Filter so we see moves only for relevant square 
  moves = input.split("START").last.delete("END")
  moves = moves.chomp.split("\n").join().split(" ")
  moves = moves.map{ |move| move if move.split(":").first.eql? square.to_s} 
  moves = moves.compact.join(",")
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

  moves = input.split("<").last.delete(">")
end

while(true)

  ser_val = ""
  while(ser_val.eql? "")
    ser_val = @spR.read
  end

  #read_val += "\n"
  #@spW.write read_val

  #Get all possible moves
  moves = getMoves ser_val

  puts "Possible moves for #{ser_val}: #{moves}"

  #mv = gets

  #cpuMv = makeMove mv
  #puts "Return move #{cpuMv} \n"
end




