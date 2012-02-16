#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;


int main()
{



}


//Find the square of piece the move is referring to in SAN, i.e. Nf3
string findPiece(string move){

  switch(move.size()){
    case(3)

  }
}


//Tell which piece it is by first character
//Call function to find where the piece is on board
char identifyPiece(string move){
  switch(move.at(0)){
    case('N'):
      knightLocations();
      break;
    case('Q'):
      queenLocations();
      break;
    case('R'):
      rookLocations();
      break;
    case('B'):
      bishopLocations();
      break;
    case('K'):
      kingLocations();
      break;
    default:
      pawnLocations();

  }


}

void knightLocations(std::vector &locations){

  
}

void queenlocations(std::vector &locations){

  
}

void bishopLocations(std::vector &locations){

  
}

void rookLocations(std::vector &locations){

  
}

void pawnLocations(std::vector &locations){

  
}

void kingLocations(std::vector &locations){

  
}
