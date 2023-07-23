; ModuleID = 'test.ll'
source_filename = "test.ll"

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone willreturn
define i32 @callercaller() local_unnamed_addr #0 {
  ret i32 3
}

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone willreturn }
