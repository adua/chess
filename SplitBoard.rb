
board = "r\sn\sb\sq\sk\sb\sn\sr\np\sp\sp\sp\sp\sp\sp\n.\s.\s.\s.\s.\s.\s.\s.\n.\s.\s.\s.\s.\s.\s.\s.\n.\s.\s.\s.\s.\s.\s.\s.\n.\s.\s.\s.\s.\s.\s.\s.\nP\sP\sP\sP\sP\sP\sP\sP\nR\sN\sB\sQ\sK\sB\sN\sR"
 
def boardSplit board
 
  chess_board = []
  rows = board.split("\n")
  rows.each do |row|
    chess_board.push(row.split(" "))
  end
  chess_board
end

