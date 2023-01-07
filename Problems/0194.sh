// original
for i in $(head -n1 file.txt | wc -w | xargs seq 1); do cut -d ' ' -f$i file.txt | xargs; done

// same idea, little bit more elegant
head -n1 file.txt | wc -w | xargs seq 1 | xargs -n1 -i{} sh -c "cut -d' ' -f{} file.txt | xargs"
