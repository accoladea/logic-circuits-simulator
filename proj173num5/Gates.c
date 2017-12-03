/*
 * File: Gates.c
 * Creator: George Ferguson
 * Edited by Islomzhan Akhmedov. Added NOR, NAND & other functions
 * Created: Sun Nov 27 14:08:51 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "Gates.h"

typedef struct Gate {
	int numInputs;
	Value **inputs;
	Value *output;
	void (*update)(struct Gate*);
	void (*print)(struct Gate*);
} Gate;

static Gate* new_Gate() {
	Gate* this = (Gate*)malloc(sizeof(Gate));
	this->output = new_Value(false);
	return this;
}

Gate** new_Gate_array(int len) {
	Gate** this = (Gate**)calloc(sizeof(Gate*), len);
	return this;
}

void Gate_update(Gate *this) {
	this->update(this);
}

void Gate_print(Gate *this) {
	this->print(this);
}

int Gate_numInputs(Gate* this) {
	return this->numInputs;
}

Value* Gate_getInput(Gate* this, int index) {
	return this->inputs[index];
}

Value* Gate_getOutput(Gate* this) {
	return this->output;
}

bool Gate_hasInput(Gate* this, Value* value) {
	for (int i=0; i < this->numInputs; i++) {
		if (this->inputs[i] == value) {
			return true;
		}
	}
	return false;
}

bool Gate_feedsInto(Gate* this, Gate* other) {
	return Gate_hasInput(other, this->output);
}

static Gate* new_UnaryGate() {
	Gate* this = new_Gate();
	this->numInputs = 1;
	this->inputs = new_Value_array(this->numInputs);
	return this;
}

static void UnaryGate_print(Gate *this, char* op) {
	printf("%s(", op);
	Value_print(this->inputs[0]);
	printf(") -> ");
	Value_print(this->output);
}


static Gate* new_BinaryGate() {
	Gate* this = new_Gate();
	this->numInputs = 2;
	this->inputs = new_Value_array(this->numInputs);
	return this;
}

static void BinaryGate_print(Gate *this, char *op) {
	printf("%s(", op);
	Value_print(this->inputs[0]);
	printf(",");
	Value_print(this->inputs[1]);
	printf(") -> ");
	Value_print(this->output);
}

static void Inverter_update(Gate *this) {
	Value_setValue(this->output, !Value_getValue(this->inputs[0]));
}

static void Inverter_print(Gate *this) {
	UnaryGate_print(this, "NEG");
}

Gate* new_Inverter(Value *input) {
	Gate* this = new_UnaryGate();
	this->inputs[0] = input;
	this->update = Inverter_update;
	this->print = Inverter_print;
	return this;
}

// FOR AND
static void AndGate_update(Gate *this) {
	Value_setValue(this->output, Value_getValue(this->inputs[0]) && Value_getValue(this->inputs[1]));
}

static void AndGate_print(Gate *this) {
	BinaryGate_print(this, "AND");
}

Gate* new_AndGate(Value *input1, Value *input2) {
	Gate* this = new_BinaryGate();
	this->inputs[0] = input1;
	this->inputs[1] = input2;
	this->update = AndGate_update;
	this->print = AndGate_print;
	return this;
}

// FOR NAND
static void NandGate_update(Gate *this) {
    bool value = Value_getValue(this->inputs[0]) && Value_getValue(this->inputs[1])?false:true;
    Value_setValue(this->output, value);
}

static void NandGate_print(Gate *this) {
    BinaryGate_print(this, "NAND");
}

Gate* new_NandGate(Value *input1, Value *input2) {
    Gate* this = new_BinaryGate();
    this->inputs[0] = input1;
    this->inputs[1] = input2;
    this->update = NandGate_update;
    this->print = NandGate_print;
    return this;
}

// FOR OR
static void OrGate_update(Gate *this) {
	Value_setValue(this->output, Value_getValue(this->inputs[0]) || Value_getValue(this->inputs[1]));
}

static void OrGate_print(Gate *this) {
	BinaryGate_print(this, "OR");
}

Gate* new_OrGate(Value *input1, Value *input2) {
	Gate* this = new_BinaryGate();
	this->inputs[0] = input1;
	this->inputs[1] = input2;
	this->update = OrGate_update;
	this->print = OrGate_print;
	return this;
}

// FOR NOR
static void NorGate_update(Gate *this) {
    bool value;
    value = Value_getValue(this->inputs[0]) || Value_getValue(this->inputs[1])?false:true;
    Value_setValue(this->output, value);
}

static void NorGate_print(Gate *this) {
    BinaryGate_print(this, "NOR");
}

Gate* new_NorGate(Value *input1, Value *input2) {
    Gate* this = new_BinaryGate();
    this->inputs[0] = input1;
    this->inputs[1] = input2;
    this->update = NorGate_update;
    this->print = NorGate_print;
    return this;
}

// FOR NAND 3Gate
static void Nand3Gate_update(Gate *this) {
    bool value;
    value = Value_getValue(this->inputs[0]) && Value_getValue(this->inputs[1]) && Value_getValue(this->inputs[2])?false:true;
	Value_setValue(this->output, value);
}

static void Nand3Gate_print(Gate *this) {
	printf("NAND(");
	Value_print(this->inputs[0]);
	printf(",");
	Value_print(this->inputs[1]);
	printf(",");
	Value_print(this->inputs[2]);
	printf(") -> ");
	Value_print(this->output);
}

Gate* new_Nand3Gate(Value *input1, Value *input2, Value* input3) {
	Gate* this = new_Gate();
	this->numInputs = 3;
	this->inputs = new_Value_array(this->numInputs);
	this->inputs[0] = input1;
	this->inputs[1] = input2;
	this->inputs[2] = input3;
	this->update = Nand3Gate_update;
	this->print = Nand3Gate_print;
	return this;
}

// FOR NOR 4Gate
static void Nor4Gate_update(Gate *this) {
    bool value;
    value = Value_getValue(this->inputs[0]) || Value_getValue(this->inputs[1]) || Value_getValue(this->inputs[2]) || Value_getValue(this->inputs[3])?false:true;
	Value_setValue(this->output, value);
}

static void Nor4Gate_print(Gate *this) {
	printf("NOR(");
	Value_print(this->inputs[0]);
	printf(",");
	Value_print(this->inputs[1]);
	printf(",");
	Value_print(this->inputs[2]);
	printf(",");
	Value_print(this->inputs[3]);
	printf(") -> ");
	Value_print(this->output);
}

Gate* new_Nor4Gate(Value *input1, Value *input2, Value* input3, Value* input4) {
	Gate* this = new_Gate();
	this->numInputs = 4;
	this->inputs = new_Value_array(this->numInputs);
	this->inputs[0] = input1;
	this->inputs[1] = input2;
	this->inputs[2] = input3;
	this->inputs[3] = input4;
	this->update = Nor4Gate_update;
	this->print = Nor4Gate_print;
	return this;
}
