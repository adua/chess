
chess_board = board.split("|").reverse

def multIndex (sBox,element)
  indices =[]
  for i in 0..(sBox.size-1) 
   indices.push(i) if sBox[i].chr.eql? element
  end
  indices
end

def findPiece (chess_board, piece)
coords = []  
  chess_board.each do |row|
    cols = multIndex(row, piece)
    cols.each do |col|
       coords.push([chess_board.index(row), col])
    end
  end
  coords
end
