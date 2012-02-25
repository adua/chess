
def defineCoord move
  move = move.split("-")
  moveFrom = move[0]
  moveTo = move[1]
  
  coordFrom = []
  coordRow = moveFrom[1] - 49
  coordCol = moveFrom[0] - 97
  coordFrom = [coordRow, coordCol]

  coordTo = []
  coordRow = moveTo[1] - 49
  coordCol = moveTo[0] - 97
  coordTo = [coordRow, coordCol] 
  
  coordsFinal = []
  coordsFinal = [coordFrom, coordTo]
  
  coordsFinal
  
end

coordsFinal = defineCoord(move)
puts coordsFinal.inspect 
print "\n"




