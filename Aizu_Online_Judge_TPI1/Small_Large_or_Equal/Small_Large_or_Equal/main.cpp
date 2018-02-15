//
//  main.cpp
//  Small_Large_or_Equal
//
//  Created by βshort on 2018/02/11.
//  Copyright © 2018年 sample-user. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
  int a ,b;
  cin >> a >> b;
  if ( a == b){
    cout << "a == b" << endl;
  }else if(a < b){
    cout << "a < b" << endl;
  }else{
    cout << "a > b" << endl;
  }
}
