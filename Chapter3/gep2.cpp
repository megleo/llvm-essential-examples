#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Verifier.h>
#include <iostream>

using namespace llvm;

int main() {
    LLVMContext context;
    Module module("getGEP_example", context);

    // 创建一个结构体类型 { i32, i32 }
    StructType* structType = StructType::create(context, {Type::getInt32Ty(context), Type::getInt32Ty(context)});
    
    // 创建一个函数类型 void()，无参数无返回值
    FunctionType* functionType = FunctionType::get(Type::getVoidTy(context), false);
    
    // 创建一个函数 getGEP_example
    Function* function = Function::Create(functionType, Function::ExternalLinkage, "getGEP_example", module);

    // 创建函数的基本块，并设置为插入点
    BasicBlock* basicBlock = BasicBlock::Create(context, "entry", function);
    IRBuilder<> builder(basicBlock);

    // 创建结构体的全局变量
    GlobalVariable* structVar = new GlobalVariable(module, structType, false, GlobalValue::ExternalLinkage, Constant::getNullValue(structType), "myStruct");

    // 计算结构体第二个元素的指针偏移量
    Value* gep = builder.CreateGEP(structType, structVar, {ConstantInt::get(Type::getInt32Ty(context), 0), ConstantInt::get(Type::getInt32Ty(context), 1)});

    // 打印生成的指令
    gep->print(llvm::outs());

    // 验证函数的正确性
    verifyFunction(*function);
    module.print(errs(), nullptr);

    return 0;
}
