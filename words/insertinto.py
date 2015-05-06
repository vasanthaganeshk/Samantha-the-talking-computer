f1 = open('adj1.txt', 'r')
f2 = open('adverb1.txt', 'r')
f3 = open('conjunctions.txt', 'r')
f4 = open('determiners.txt', 'r')
f5 = open('nouns.txt', 'r')
f6 = open('prefix.txt', 'r')
f7 = open('prepositions.txt', 'r')
f8 = open('pronouns.txt', 'r')
f9 = open('suffix.txt', 'r')
f10 = open('verbs.txt', 'r')
f11 = open('punctuation.txt', 'r')
f12 = open('interjection.txt', 'r')

text1 = f1.read()
text1 = text1.split('\n')

text2 = f2.read()
text2 = text2.split('\n')

text3 = f3.read()
text3 = text3.split('\n')

text4 = f4.read()
text4 = text4.split('\n')

text5 = f5.read()
text5 = text5.split('\n')

text6 = f6.read()
text6 = text6.split('\n')

text7 = f7.read()
text7 = text7.split('\n')

text8 = f8.read()
text8 = text8.split('\n')

text9 = f9.read()
text9 = text9.split('\n')

text10 = f10.read()
text10 = text10.split('\n')

text11 = f11.read()
text11 = text11.split('\n')

text12 = f12.read()
text12 = text12.split('\n')


# unwan1 = text1.count('')
# print unwan1
# unwan2 = text2.count('')
# print unwan2
# unwan3 = text3.count('')
# print unwan3
# unwan1 = text1.count('')
# print unwan1
# unwan4 = text4.count('')
# print unwan4
# unwan5 = text5.count('')
# print unwan5
# unwan6 = text6.count('')
# print unwan6
# unwan7 = text7.count('')
# print unwan7
# unwan8 = text8.count('')
# print unwan8
# unwan9 = text9.count('')
# print unwan9
# unwan10 = text10.count('')
# print unwan10
into = []

flag1 = 0
flag2 = 0
flag3 = 0
flag4 = 0
flag5 = 0
flag6 = 0
flag7 = 0
flag8 = 0
flag9 = 0
flag10 = 0
flag11 = 0
flag12 = 0


for i in xrange(len(text5)):
	print 'INSERT INTO words VALUES( {},'.format(i+1),
	if flag1:
		print 'NULL,',
	elif text1[i]:
		print '"{}",'.format(text1[i].strip()),
		if i == len(text1) - 2:
			flag1 = 1;
	
	if flag2:
		print 'NULL,',
	elif text2[i]:
		print '"{}",'.format(text2[i].strip()),
		if i == len(text2) - 2:
			flag2 = 1;
	
	if flag3:
		print 'NULL,',
	elif text3[i]:
		print '"{}",'.format(text3[i].strip()),
		if i == len(text3) - 2:
			flag3 = 1;
	

	if flag4:
		print 'NULL,',
	elif text4[i]:
		print '"{}",'.format(text4[i].strip()),
		if i == len(text4) - 2:
			flag4 = 1;
	

	if flag5:
		print 'NULL,',
	elif text5[i]:
		print '"{}",'.format(text5[i].strip()),
		if i == len(text5) - 2:
			flag5 = 1;

	if flag6:
		print 'NULL,',
	elif text6[i]:
		print '"{}",'.format(text6[i].strip()),
		if i == len(text6) - 2:
			flag6 = 1;
	
	if flag7:
		print 'NULL,',
	elif text7[i]:
		print '"{}",'.format(text7[i].strip()),
		if i == len(text7) - 2:
			flag7 = 1;

	if flag8:
		print 'NULL,',
	elif text8[i]:
		print '"{}",'.format(text8[i].strip()),
		if i == len(text8) - 2:
			flag8 = 1;
	
	if flag9:
		print 'NULL,',
	elif text9[i]:
		print '"{}",'.format(text9[i].strip()),
		if i == len(text9) - 2:
			flag9 = 1;
	
	if flag10:
		print 'NULL,',
	elif text10[i]:
		print '"{}",'.format(text10[i].strip()),
		if i == len(text10) - 2:
			flag10 = 1;

	if flag11:
		print 'NULL,',
	elif text11[i]:
		print '"{}",'.format(text11[i].strip()),
		if i == len(text11) - 2:
			flag11 = 1;

	if flag12:
		print 'NULL,',
	elif text12[i]:
		print '"{}",'.format(text12[i].strip()),
		if i == len(text12) - 2:
			flag12 = 1;
	print 'NULL);'
	
