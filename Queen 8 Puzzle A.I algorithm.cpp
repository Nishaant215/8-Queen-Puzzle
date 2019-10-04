#include<iostream>

using namespace std;

class Queen8 {

public:
   void solution();
   void placeQueenInRow(int row);
   bool attackQueen(int row, int col);
   bool checkRightDiag(int row, int col);
   bool checkLeftDiag(int row, int col);
   bool checkSameCol(int row, int col);\
void print_solution();


private:
   int QueenBoard[8];
   int solution_count = 0;
};

int main() {

   Queen8 P;

   P.solution();

}

void Queen8::solution(){
   placeQueenInRow(0);
}

void Queen8::placeQueenInRow(int row){
      
   for(int col = 0; col<8; col++){
      
      if( ! attackQueen(row, col) ){
         QueenBoard[row] = col;
         
         if(row == 7){ 
            print_solution();   }        
         else { 
            placeQueenInRow( row+1);  }
      }
   }
}

void Queen8::print_solution(){
 
   solution_count++;
 
   cout<<"Soultion "<< solution_count<<": ";
 
   for(int i = 0; i <=7; i++){
      cout<<QueenBoard[i]<<", ";   
   }
   cout<<endl;
   

}




bool Queen8::attackQueen(int row, int col){
   
   if ( checkRightDiag(row, col) || checkLeftDiag(row, col) || checkSameCol(row, col) ){
      return true;
   }   
   else {
      return false;
   }
}

bool Queen8::checkRightDiag(int row, int col){

   for(int i =1; ( (i <= row) && (i <= 7- col) ) ; i++){       //reads right to left
      if(QueenBoard[row - i] == col + i){  
         return true;   
      }   
   }
   return false;
}


bool Queen8::checkLeftDiag(int row, int col){
  
   for(int i =1; ( (i <= row) && ( i <= col) ); i++){            //reads the rows left to right
      if(QueenBoard[row - i] == col - i){  
         return true;
      }   
   }
   return false;
}

bool Queen8::checkSameCol(int row, int col){

   for(int i = 0; i<row ; i++){                        
      if(QueenBoard[i] == col ){           
         return true;        
      }
   }
   return  false;
}




