#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"
#include <math.h>

static char* b2s(bool b) { return b ? "T" : "F"; }
static Circuit* Circuits_partA(void);
static Circuit* Circuits_partB(void);
static Circuit* Circuits_partC(void);
static void testing_partA(Circuit* circuit, bool in0, bool in1, bool in2);
static void testing_partB(Circuit* circuit, bool in0, bool in1, bool in2);
static void testing_partC(Circuit* circuit, bool in0, bool in1);

int main(int argc, char **argv) {
    
    //Part A {[X AND (NOT Y)] OR [Y AND Z]}
    
    printf("Part A {[X AND (NOT Y)] OR [Y AND Z]}\n");
    Circuit* ca = Circuits_partA();
    testing_partA(ca, false, false, false);
    testing_partA(ca, false, false, true);
    testing_partA(ca, false, true, false);
    testing_partA(ca, false, true, true);
    testing_partA(ca, true, false, false);
    testing_partA(ca, true, false, true);
    testing_partA(ca, true, true, false);
    testing_partA(ca, true, true, true);
    
    //Part B {[X NAND (NOT Y)] NOR [Y NAND Z]}
   
    printf("Part B {[X NAND (NOT Y)] NOR [Y NAND Z]}\n");
    Circuit* cb = Circuits_partB();
    testing_partB(cb, false, false, false);
    testing_partB(cb, false, false, true);
    testing_partB(cb, false, true, false);
    testing_partB(cb, false, true, true);
    testing_partB(cb, true, false, false);
    testing_partB(cb, true, false, true);
    testing_partB(cb, true, true, false);
    testing_partB(cb, true, true, true);
    
    //Part C {[Y AND X] OR [(NOT X) AND (NOT Y)]}
    
    printf("Part C {[Y AND X] OR [(NOT X) AND (NOT Y)]}\n");
    Circuit* cc = Circuits_partC();
    testing_partC(cc, false, false);
    testing_partC(cc, false, true);
    testing_partC(cc, true, false);
    testing_partC(cc, true, true);
}

/**
 * Nice Circuit 1 -> {[X AND (NOT Y)] OR [Y AND Z]}
 */
static Circuit* Circuits_partA() {
    Value* in0 = new_Value(false);
    Value* in1 = new_Value(false);
    Value* in2 = new_Value(false);
    
    // Invert Y
    //0
    Gate* inv = new_Inverter(in1);
    
    //AND gates
    //1 [X AND (NOT Y)]
    Gate* and0 = new_AndGate(in0, Gate_getOutput(inv));
    //2 [Y AND Z]
    Gate* and1 = new_AndGate(in1, in2);
    
    //OR gate
    //3 {[X AND (NOT Y)] OR [Y AND Z]}
    Gate* or3 = new_OrGate(Gate_getOutput(and0), Gate_getOutput(and1));
    
    Value** inputs = new_Value_array(3);
    inputs[0] = in0;
    inputs[1] = in1;
    inputs[2] = in2;
    
    Value** outputs = new_Value_array(1);
    outputs[0] = Gate_getOutput(or3);
    Gate** gates = new_Gate_array(4);
    gates[0]= inv;
    gates[1] = and0;
    gates[2] = and1;
    gates[3] = or3;
//new_Circuit(int numInputs, Value **inputs, int numOutputs, Value **outputs, int numGates, Gate **gates)
    return new_Circuit(3, inputs, 1, outputs, 4, gates);
}

static void testing_partA(Circuit* circuit, bool in0, bool in1, bool in2) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    Circuit_setInput(circuit, 2, in2);
    //Circuit_dump(circuit);
    Circuit_update(circuit);
    bool out0 = Circuit_getOutput(circuit, 0);
    printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
}

/**
 * Nice Circuit 2 -> {[X NAND (NOT Y)] NOR [Y NAND Z]}
 */

static Circuit* Circuits_partB() {
    Value* in0 = new_Value(false);
    Value* in1 = new_Value(false);
    Value* in2 = new_Value(false);
    
    // invert y
    //0
    Gate* inv = new_Inverter(in1);
    
    //NAND gates
    //1 [X NAND (NOT Y)]
    Gate* and0 = new_NandGate(in0, Gate_getOutput(inv));
    //2 [Y NAND Z]
    Gate* and1 = new_NandGate(in1, in2);
    
    //NOR gate
    //3 {[X NAND (NOT Y)] NOR [Y NAND Z]}
    Gate* or3 = new_NorGate(Gate_getOutput(and0), Gate_getOutput(and1));
    
    Value** inputs = new_Value_array(3);
    inputs[0] = in0;
    inputs[1] = in1;
    inputs[2] = in2;
    
    Value** outputs = new_Value_array(1);
    outputs[0] = Gate_getOutput(or3);
    Gate** gates = new_Gate_array(4);
    gates[0]= inv;
    gates[1] = and0;
    gates[2] = and1;
    gates[3] = or3;
    //new_Circuit(int numInputs, Value **inputs, int numOutputs, Value **outputs, int numGates, Gate **gates)
    return new_Circuit(3, inputs, 1, outputs, 4, gates);
}

static void testing_partB(Circuit* circuit, bool in0, bool in1, bool in2) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    Circuit_setInput(circuit, 2, in2);
    //Circuit_dump(circuit);
    Circuit_update(circuit);
    bool out0 = Circuit_getOutput(circuit, 0);
    printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
}

/**
 * Nice Circuit 3 -> {[Y AND X] OR [(NOT X) AND (NOT Y)]}
 */
static Circuit* Circuits_partC() {
    Value* in0 = new_Value(false);
    Value* in1 = new_Value(false);
    
    //1 invert y
    //NOT Y
    Gate* inv0 = new_Inverter(in0);
    
    //2 invert x
    //NOT X
    Gate* inv1 = new_Inverter(in1);
    
    //AND gate
    //3 [(NOT X) AND (NOT Y)]
    Gate* and1 = new_AndGate(Gate_getOutput(inv0), Gate_getOutput(inv1));
    
    //AND gate
    //4 [Y AND X]
    Gate* and0 = new_AndGate(in0, in1);
    
    //OR gate
    //5 {[Y AND X] OR [(NOT X) AND (NOT Y)]}
    Gate* or0 = new_OrGate(Gate_getOutput(and0), Gate_getOutput(and1));
    
    Value** inputs = new_Value_array(2);
    inputs[0] = in0;
    inputs[1] = in1;
    
    Value** outputs = new_Value_array(1);
    outputs[0] = Gate_getOutput(or0);
    
    Gate** gates = new_Gate_array(5);
    gates[0] = inv0;
    gates[1] = inv1;
    gates[2] = and0;
    gates[3] = and1;
    gates[4] = or0;
    
    //new_Circuit(int numInputs, Value **inputs, int numOutputs, Value **outputs, int numGates, Gate **gates)
    return new_Circuit(2, inputs, 1, outputs, 5, gates);
}

static void testing_partC(Circuit* circuit, bool in0, bool in1) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    //Circuit_dump(circuit);
    Circuit_update(circuit);
    bool out0 = Circuit_getOutput(circuit, 0);
    printf("%s %s -> %s\n", b2s(in0), b2s(in1), b2s(out0));
}
