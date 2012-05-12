require 'rubygems'
require 'serialport'

sp1 = "/dev/ttyACM0"
sp2 = "/dev/ttyACM1"
baud = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE

spR = SerialPort.new(sp1, baud, data_bits, stop_bits, parity)
spW = SerialPort.new(sp2, baud)

while(true) 
  read_val = ""
  while(read_val.eql? "")
    read_val = spR.read
    puts "SerialRead: #{read_val}"
  end

  read_val += "\n"
  spW.write read_val
end
#puts sp.read   # hopefully "OK" ;-)
