The general assumptions are as follows:
• The top three students of a school consisting of 4 branches, with 10 students in each branch, will be announced. (Use numbers for malloc)
• Student information is stored in the "ogrenci.db" file as pairs.
• The information includes TCKN, Sube (branch), Adi (name), Soyadi (surname), Cinsiyet (gender), and DersOrtalamasi (grade average).

Based on this information:

Define an ENUM for Gender (Male, Female).
Define a structure named Ogrenci with TCKN, Sube, Adi, Soyadi, Cinsiyet, and DersOrtalamasi.
Define an array called DiziOgrenci[Sube][Ogrenci] using this structure and allocate memory for this array using malloc (the number of branches and students is given above).
Write to the "ogrenci.db" file in pairs using a for/while loop. Create a function called BilgiYaz for writing.
Read the "ogrenci.db" file in pairs using a for/while loop. Create a function called Bilgioku for reading.
Create a function called SonucYaz that calculates and displays the top three students.



