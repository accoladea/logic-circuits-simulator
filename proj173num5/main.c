//
//  main.c
//  proj173num5
//
//  Created by Zhan Dov on 12/2/17.
//  Copyright © 2017 accolade. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"
#include <math.h>
static char* b2s(bool b) { return b ? "T" : "F"; }
/**
 * Two AND gates connected to make a 3-input AND circuit.
 *
static Circuit* Circuits_and3(void);
static bool test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2);
*/
static Circuit* Circuits_niceCircuit_a(void);
static void test_niceCircuit_a(Circuit* circuit, bool in0, bool in1);

int main(int argc, char **argv) {
//    Circuit* c = Circuits_and3();
//    double num_rows = pow(2, 3);
//
//    printf("Some input(s) false: should be false\n");
//    for (int i = 1; i<=num_rows; i++) {
//        int x=0,y=0,z=0;
//        if(i==2) z=1;
//        else if (i==3) {y = 1;}
//        else if (i==4) {z=1;y=1;}
//        else if (i==5) {x=1;}
//        else if (i==6) {x=1;z=1;}
//        else if (i==7) {x=1;y=1;}
//        else if (i==8) {x=1;y=1;z=1;};
//        bool print = test3In1Out(c, x, y, z);
//        if (print == false) {
//            printf("%d) %s %s %s -> %s\n", i,b2s(x), b2s(y), b2s(z), b2s(print));
//        }
//    }
//
//    printf("All inputs true: should be true\n");
//    for (int i = 1; i<=num_rows; i++) {
//        int x=0,y=0,z=0;
//        if(i==2) z=1;
//        else if (i==3) {y = 1;}
//        else if (i==4) {z=1;y=1;}
//        else if (i==5) {x=1;}
//        else if (i==6) {x=1;z=1;}
//        else if (i==7) {x=1;y=1;}
//        else if (i==8) {x=1;y=1;z=1;};
//        bool print = test3In1Out(c, x, y, z);
//        if (print == true) {
//            printf("%d) %s %s %s -> %s\n", i,b2s(x), b2s(y), b2s(z), b2s(print));
//        }
//    }
//
    
    Circuit* niceCircuit_a = Circuits_niceCircuit_a();
    test_niceCircuit_a(niceCircuit_a, b2s(0), b2s(0));
//    test_niceCircuit_a(niceCircuit_a, b2s(1), b2s(0));
//    test_niceCircuit_a(niceCircuit_a, b2s(0), b2s(1));
//    test_niceCircuit_a(niceCircuit_a, b2s(1), b2s(1));
}

/**
 * Two AND gates connected to make a 3-input AND circuit.
 *
static Circuit* Circuits_and3() {
    Value* in0 = new_Value(false);
    Value* in1 = new_Value(false);
    Value* in2 = new_Value(false);
    Gate* and0 = new_AndGate(in0, in1);
    Gate* and1 = new_AndGate(Gate_getOutput(and0), in2);
    
    Value** inputs = new_Value_array(3);
    inputs[0] = in0;
    inputs[1] = in1;
    inputs[2] = in2;
    Value** outputs = new_Value_array(1);
    outputs[0] = Gate_getOutput(and1);
    Gate** gates = new_Gate_array(2);
    gates[0] = and0;
    gates[1] = and1;
    return new_Circuit(3, inputs, 1, outputs, 2, gates);
}

static bool test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    Circuit_setInput(circuit, 2, in2);
    //Circuit_dump(circuit);
    Circuit_update(circuit);
    bool out0 = Circuit_getOutput(circuit, 0);
    //printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
    return out0;
}*/
/**
 * Nice Circuit 1 -> xY+yz where a capital letter Y stands for not
 *
 */
static Circuit* Circuits_niceCircuit_a() {
    Value* in0 = new_Value(false);
    Value* in1 = new_Value(false);
//    Value* in2 = new_Value(false);
//    Value* in3 = new_Value(false);
//
    /*
     
     Value* in2 = new_Value(false);
     Gate* and0 = new_AndGate(in0, in1);
     Gate* and1 = new_AndGate(Gate_getOutput(and0), in2);
     
     Value** inputs = new_Value_array(3);
     
     */
    
    //Gate* not_in1 = new_Inverter(in1);
    Gate* and0 = new_AndGate(in0, in1);
    
//    Gate* and1 = new_AndGate(Gate_getOutput(and0), in2);
    
    Value** inputs = new_Value_array(2);//4
    inputs[0] = in0;
    inputs[1] = in1;
//    inputs[2] = in2;
//    inputs[3] = in3;
    Value** outputs = new_Value_array(1);
    //outputs[0] = Gate_getOutput(and1);
    Gate** gates = new_Gate_array(2);
    gates[0] = and0;
    //gates[1] = and1;
   // new_Circuit(int numInputs, Value **inputs, int numOutputs, Value **outputs, int numGates, Gate **gates)
    return new_Circuit(2, inputs, 1, outputs, 1, gates);
}

static void test_niceCircuit_a(Circuit* circuit, bool in0, bool in1) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    //Circuit_dump(circuit);
    Circuit_update(circuit);
    bool out0 = Circuit_getOutput(circuit, 0);
    printf("%s %s -> %s\n", b2s(in0), b2s(in1), b2s(out0));
    //return out0;
}


