/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 *****************************************************************************/

/*****************************************************************************
 
  display.cpp -- 
 
  Original Author: Rocco Jonack, Synopsys, Inc.

 *****************************************************************************/
 
/*****************************************************************************
 
  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.
 
      Name, Affiliation, Date:
  Description of Modification:
 
 *****************************************************************************/

#include <systemc.h>
#include "display.h"

#include "fc4sc.hpp"

void display::entry(){

  //  Reading Data when valid if high
  tmp1 = result.read();
  cout << "Display : " << tmp1 << " "
      << "at time " << sc_time_stamp().to_double() << endl;
  i++;

  this->out_cg.sample(result, output_data_ready);


  if(i == 24) {
    cout << "Simulation of " << i << " items finished"
	 << " at time " << sc_time_stamp().to_double() << endl;

    fc4sc::global_access::coverage_save("coverage_results.xml");
      
    sc_stop();
  };
}
// EOF
