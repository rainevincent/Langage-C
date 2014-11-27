.name "Zork"
.comment "Wahoo, un commentaire O_O"
sti r1, %:tamere, %1
and r1, %0, r1
tamere: live %1
zjmp %:tamere
