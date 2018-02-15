//
//  main.cpp
//  range
//
//  Created by βshort on 2018/02/11.
//  Copyright © 2018年 sample-user. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  if ( (a < b) && (b < c) ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
