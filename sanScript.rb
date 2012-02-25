@valid_range = 0..7

def knightMoves pos
  moves = []
  moves[0]= [pos[0]+2, pos[1]+1]
  moves[1] = [pos[0]+2, pos[1]-1]
  moves[2] = [pos[0]+1, pos[1]-2]
  moves[3] = [pos[0]-1, pos[1]-2]
  moves[4] = [pos[0]-2, pos[1]+1]
  moves[5] = [pos[0]-2, pos[1]-1]
  moves[6] = [pos[0]+1, pos[1]+2]
  moves[7] = [pos[0]-1, pos[1]+2]
  moves.map{ |move| move if valid(move) }.compact
end


def bishopMoves pos
  moves = []
  row = pos[0]
  col = pos[1]
  _row = row
  _col = col
  #Head NE
  while valid([_row, _col])
    moves.push([_row, _col])
    _row += 1
    _col += 1
  end

  _row = row
  _col = col
 #Head NW
  while valid([_row, _col])
    moves.push([_row, _col])
    _row += 1
    _col -= 1
  end
  
  _row = row
  _col = col
 #Head SE
  while valid([_row, _col])
    moves.push([_row, _col])
    _row -= 1
    _col += 1
  end

  _row = row
  _col = col
 #Head SW
  while valid([_row, _col])
    moves.push([_row, _col])
    _row -= 1
    _col -= 1
  end

  moves.uniq!
end

def rookMoves pos
  moves = []
  row = pos[0]
  col = pos[1]
  _row = row
  _col = col
  #Head E
  while valid([_row, _col])
    moves.push([_row, _col])
    _col += 1
  end

  _row = row
  _col = col
 #Head W
  while valid([_row, _col])
    moves.push([_row, _col])
    _col -= 1
  end
  
  _row = row
  _col = col
 #Head S
  while valid([_row, _col])
    moves.push([_row, _col])
    _row -= 1
  end

  _row = row
  _col = col
 #Head N
  while valid([_row, _col])
    moves.push([_row, _col])
    _row += 1
  end

  moves.uniq!

end

def queenMoves pos
  _bMoves = bishopMoves pos
  _rMoves = rookMoves pos
  _bMoves.concat(_rMoves).uniq!
end

def pawnMoves pos
  moves = []
  row = pos[0]
  col = pos[1]
  moves.push([row+1, col])
  moves
end

def valid pos
  (@valid_range.include? pos[0]) && (@valid_range.include? pos[1])
end
