//
//  main.cpp
//  Pra_1
//
//  Created by βshort on 2018/02/09.
//  Copyright © 2018年 sample-user. All rights reserved.
//

#include <iostream>
using namespace std;

//関数を定義する
void output_string(){
  cout << "output_string関数を使用しました。" << endl;
  //出力
   std::cout << "Hello, World!\n";
  //改行するときは、endlをつける
  cout << "Hello, World!" << endl;
}

int main(int argc, const char * argv[]) {
  int a;
  //配列
  int index[] = { 1, 4, 5, 3, 5};
  // output_string();
  //入力する
  cin >> a ;
  cout << a << endl;
  
  //条件分岐
  if( a < 5){
    cout << "入力した値は、5より小さいです。" << endl;
  }else{
    cout << "入力した値は、5以上です。" << endl;
  }
  //for文で繰り返し
  for(int i = 0 ; i < 10 ; i++){
    cout << "******" << endl;
  }
  for(int i = 0 ; i < 5 ; i++){
    cout << index[i] << endl;
  }
 
  
  return 0;
}
