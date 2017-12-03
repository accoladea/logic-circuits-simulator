////Works 100% Part B of proj 5
//#include <stdio.h>
//#include <stdlib.h>
//#include "Circuit.h"
//#include <math.h>
//
//static Circuit* Circuits_partB(void);
//static char* b2s(bool b) { return b ? "T" : "F"; }
//static void testing_partB(Circuit* circuit, bool in0, bool in1, bool in2);
////static void test_niceCircuit_a(Circuit* circuit, bool in0, bool in1);
//
//int main(int argc, char **argv) {
//    Circuit* c = Circuits_partB();
//    testing_partB(c, false, false, false);
//    testing_partB(c, false, false, true);
//    testing_partB(c, false, true, false);
//    testing_partB(c, false, true, true);
//    testing_partB(c, true, false, false);
//    testing_partB(c, true, false, true);
//    testing_partB(c, true, true, false);
//    testing_partB(c, true, true, true);
//}
//
///**
// * Nice Circuit 2 -> [X NAND (NOT Y)] NOR [Y NAND Z]
// */
//static Circuit* Circuits_partB() {
//    Value* in0 = new_Value(false);
//    Value* in1 = new_Value(false);
//    Value* in2 = new_Value(false);
//    
//    // invert y
//    //0
//    Gate* inv = new_Inverter(in1);
//    
//    //and gates
//    //1 xY
//    Gate* and0 = new_NandGate(in0, Gate_getOutput(inv));
//    //2 yz
//    Gate* and1 = new_NandGate(in1, in2);
//    
//    //or gate
//    //3 xY+yz
//    Gate* or3 = new_NorGate(Gate_getOutput(and0), Gate_getOutput(and1));
//    //Gate* and2 = new_AndGate(Gate_getOutput(and0), in2);
//    
//    Value** inputs = new_Value_array(3);
//    inputs[0] = in0;
//    inputs[1] = in1;
//    inputs[2] = in2;
//    
//    Value** outputs = new_Value_array(1);
//    outputs[0] = Gate_getOutput(or3);
//    Gate** gates = new_Gate_array(4);
//    //gates[0]= inv;
//    gates[0] = inv;
//    gates[1] = and0;
//    gates[2] = and1;
//    gates[3] = or3;
//    //new_Circuit(int numInputs, Value **inputs, int numOutputs, Value **outputs, int numGates, Gate **gates)
//    return new_Circuit(3, inputs, 1, outputs, 4, gates);
//}
//
//static void testing_partB(Circuit* circuit, bool in0, bool in1, bool in2) {
//    Circuit_setInput(circuit, 0, in0);
//    Circuit_setInput(circuit, 1, in1);
//    Circuit_setInput(circuit, 2, in2);
//    //Circuit_dump(circuit);
//    Circuit_update(circuit);
//    bool out0 = Circuit_getOutput(circuit, 0);
//    printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
//}
//
//
//
