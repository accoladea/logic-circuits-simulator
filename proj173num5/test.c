//#include <stdio.h>
//#include <stdlib.h>
//#include "Circuit.h"
//#include <math.h>
//
//
//static Circuit* Circuits_and3(void);
//static char* b2s(bool b) { return b ? "T" : "F"; }
//static void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2);
////static void test_niceCircuit_a(Circuit* circuit, bool in0, bool in1);
//
//int main(int argc, char **argv) {
//    Circuit* c = Circuits_and3();
//    test3In1Out(c, false, false, false);
//    test3In1Out(c, false, false, true);
//    test3In1Out(c, false, true, false);
//    test3In1Out(c, false, true, true);
//    test3In1Out(c, true, false, false);
//    test3In1Out(c, true, false, true);
//    test3In1Out(c, true, true, false);
//    test3In1Out(c, true, true, true);
//}
//
///**
// * Nice Circuit 1 -> xY+yz where a capital letter Y stands for not
// */
//static Circuit* Circuits_and3() {
//    Value* in0 = new_Value(false);
//    Value* in1 = new_Value(false);
//    Value* in2 = new_Value(false);
//    
//    //and gates
//    //1 xY
//    Gate* and0 = new_AndGate(in0, Gate_getOutput(new_Inverter(in1)));
//    //2 yz
//    Gate* and1 = new_AndGate(in1, in2);
//    
//    //or gate xY+yz
//    Gate* or3 = new_OrGate(Gate_getOutput(and0), Gate_getOutput(and1));
//    //Gate* and2 = new_AndGate(Gate_getOutput(and0), in2);
//    
//    Value** inputs = new_Value_array(3);
//    inputs[0] = in0;
//    inputs[1] = in1;
//    inputs[2] = in2;
//
//    Value** outputs = new_Value_array(1);
//    outputs[0] = Gate_getOutput(or3);
//    Gate** gates = new_Gate_array(3);
//    gates[0] = and0;
//    gates[1] = and1;
//    gates[2] = or3;
////new_Circuit(int numInputs, Value **inputs, int numOutputs, Value **outputs, int numGates, Gate **gates)
//    return new_Circuit(3, inputs, 1, outputs, 3, gates);
//}
//
//static void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
//    Circuit_setInput(circuit, 0, in0);
//    Circuit_setInput(circuit, 1, in1);
//    Circuit_setInput(circuit, 2, in2);
//    //Circuit_dump(circuit);
//    Circuit_update(circuit);
//    bool out0 = Circuit_getOutput(circuit, 0);
//    printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
//}
//
