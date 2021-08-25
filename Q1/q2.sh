touch updated.txt
while read -rd\. sntc; do printf "%s. " "${sntc^}"; done < example.txt > updated.txt