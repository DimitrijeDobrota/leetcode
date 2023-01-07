// original
for word in $(tr ' ' '\n' < words.txt | sort | uniq); do grep -o "\<$word\>" words.txt | wc -l | xargs echo $word; done | sort -k2 -nr

// using uniq -c instead of counting word by word
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr | awk '{ print $2, $1  }'
