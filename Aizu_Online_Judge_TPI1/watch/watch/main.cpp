//
//  main.cpp
//  watch
//
//  Created by βshort on 2018/02/11.
//  Copyright © 2018年 sample-user. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
  int time, hours, minuts, seconds;
  cin >> time ;
  hours = time / 3600;
  minuts = (time % 3600) / 60;
  seconds = (time % 3600) % 60;
  
  cout << hours << ":" << minuts << ":" << seconds << endl;
  
}
