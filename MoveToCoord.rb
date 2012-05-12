
def numToCoord number
  _col = number%8
  _row = (number/8).floor
  coord = [_row, _col]  
end


def moveToCoord move
  coords = []
  moves = move.split(":")
  moves.each do |number|
    coords.push(numToCoord(number.to_i))
  end
  coords
end

def coordToSAN coord
  _row = (coord[1]+97).chr
  _col = coord[0]+1
  _row+_col.to_s
end


def moveToSAN move
  san = ""
  move.each do |coord|
    san += coordToSAN(coord) 
  end
  san
end


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



