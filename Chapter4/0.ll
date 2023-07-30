; ModuleID = 'test.ll'
source_filename = "test.ll"

define internal i32 @test(i32* %X, i32* %Y) {
  %A = load i32, i32* %X, align 4
  %B = load i32, i32* %Y, align 4
  %C = add i32 %A, %B
  ret i32 %C
}

define internal i32 @caller(i32* %B) {
  %A = alloca i32, align 4
  store i32 1, i32* %A, align 4
  %C = call i32 @test(i32* %A, i32* %B)
  ret i32 %C
}

define i32 @callercaller() {
  %B = alloca i32, align 4
  store i32 2, i32* %B, align 4
  %X = call i32 @caller(i32* %B)
  ret i32 %X
}
