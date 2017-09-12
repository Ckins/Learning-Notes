sort av_sorted_stars.txt | uniq  > av_deduplicated.txt

# 按文本长度排序，file 为目标文件名
awk '{print  length($0),$0}' file |sort -nr|sed '/^[^ ]* /s///'
