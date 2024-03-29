#include "PipelineRegister.h"

PipelineRegister::PipelineRegister(bool pipe){
	bubble = new Register<bool>(pipe);

	PC = new Register<unsigned int>(pipe);
	instruction_word = new Register<unsigned int>(pipe);
	branchTarget = new Register<unsigned int>(pipe);
	A = new Register<unsigned int>(pipe);
	B = new Register<unsigned int>(pipe);
	operand2 = new Register<unsigned int>(pipe);
	aluResult = new Register<unsigned int>(pipe);
	ldResult = new Register<unsigned int>(pipe);

	isSt = new Register<bool>(pipe);
	isLd = new Register<bool>(pipe);
	isBeq = new Register<bool>(pipe);
	isBgt = new Register<bool>(pipe);
	isRet = new Register<bool>(pipe);
	isImmediate = new Register<bool>(pipe);
	isWb = new Register<bool>(pipe);
	isUbranch = new Register<bool>(pipe);
	isCall = new Register<bool>(pipe);
	isAdd = new Register<bool>(pipe);
	isSub = new Register<bool>(pipe);
	isCmp = new Register<bool>(pipe);
	isMul = new Register<bool>(pipe);
	isDiv = new Register<bool>(pipe);
	isMod = new Register<bool>(pipe);
	isLsl = new Register<bool>(pipe);
	isLsr = new Register<bool>(pipe);
	isAsr = new Register<bool>(pipe);
	isOr = new Register<bool>(pipe);
	isAnd = new Register<bool>(pipe);
	isNot = new Register<bool>(pipe);
	isMov = new Register<bool>(pipe);
}

PipelineRegister::~PipelineRegister(){
	delete bubble;

	delete PC;
	delete instruction_word;
	delete branchTarget;
	delete A;
	delete B;
	delete operand2;
	delete aluResult;
	delete ldResult;

	delete isSt;
	delete isLd;
	delete isBeq;
	delete isBgt;
	delete isRet;
	delete isImmediate;
	delete isWb;
	delete isUbranch;
	delete isCall;
	delete isAdd;
	delete isSub;
	delete isCmp;
	delete isMul;
	delete isDiv;
	delete isMod;
	delete isLsl;
	delete isLsr;
	delete isAsr;
	delete isOr;
	delete isAnd;
	delete isNot;
	delete isMov;
}

PipelineRegister& PipelineRegister::operator=(const PipelineRegister& r){
	bubble = r.bubble;

	PC = r.PC;
	instruction_word = r.instruction_word;
	branchTarget = r.branchTarget;
	A = r.A;
	B = r.B;
	operand2 = r.operand2;
	aluResult = r.aluResult;
	ldResult = r.ldResult;

	isSt = r.isSt;
	isLd = r.isLd;
	isBeq = r.isBeq;
	isBgt = r.isBgt;
	isRet = r.isRet;
	isImmediate = r.isImmediate;
	isWb = r.isWb;
	isUbranch = r.isUbranch;
	isCall = r.isCall;
	isAdd = r.isAdd;
	isSub = r.isSub;
	isCmp = r.isCmp;
	isMul = r.isMul;
	isDiv = r.isDiv;
	isMod = r.isMod;
	isLsl = r.isLsl;
	isLsr = r.isLsr;
	isAsr = r.isAsr;
	isOr = r.isOr;
	isAnd = r.isAnd;
	isNot = r.isNot;
	isMov = r.isMov;
}

void PipelineRegister::WriteBubble(bool to_bubble) {

	if (to_bubble) {
		bubble->Write(true);

		PC->Write(0x0);
		instruction_word->Write(0x68000000);

		branchTarget->Write(0x0);
		A->Write(0x0);
		B->Write(0x0);
		operand2->Write(0x0);
		aluResult->Write(0x0);
		ldResult->Write(0x0);

		isSt->Write(false);
		isLd->Write(false);
		isBeq->Write(false);
		isBgt->Write(false);
		isRet->Write(false);
		isImmediate->Write(false);
		isWb->Write(false);
		isUbranch->Write(false);
		isCall->Write(false);
		isAdd->Write(false);
		isSub->Write(false);
		isCmp->Write(false);
		isMul->Write(false);
		isDiv->Write(false);
		isMod->Write(false);
		isLsl->Write(false);
		isLsr->Write(false);
		isAsr->Write(false);
		isOr->Write(false);
		isAnd->Write(false);
		isNot->Write(false);
		isMov->Write(false);
	}
	else {
		bubble->Write(false);
	}
}


void PipelineRegister::ForwardBubble(bool to_bubble) {
	
	bubble->Write(to_bubble);

}

void PipelineRegister::clock(){
	bubble->clock();
	PC->clock();
	instruction_word->clock();
	branchTarget->clock();
	A->clock();
	B->clock();
	operand2->clock();
	aluResult->clock();
	ldResult->clock();
	isSt->clock();
	isLd->clock();
	isBeq->clock();
	isBgt->clock();
	isRet->clock();
	isImmediate->clock();
	isWb->clock();
	isUbranch->clock();
	isCall->clock();
	isAdd->clock();
	isSub->clock();
	isCmp->clock();
	isMul->clock();
	isDiv->clock();
	isMod->clock();
	isLsl->clock();
	isLsr->clock();
	isAsr->clock();
	isOr->clock();
	isAnd->clock();
	isNot->clock();
	isMov->clock();
}