#!usr/lib/python

import random
import numpy as np


def crear_sudoku(m):
	sudoku = np.zeros((9,9), dtype=int)
	sudoku[0] =  np.concatenate((m[0], m[1],  m[2]), axis=0 )
	sudoku[1] =  np.concatenate((m[2], m[0], m[1]), axis=0 )
	sudoku[2] =  np.concatenate((m[1], m[2], m[0]), axis=0 )	

	n =  np.zeros((3,3), dtype=int)
	l =  np.zeros((3,3), dtype=int)
	
	n[:, 0] = m[:, 2]
	n[:, 1] = m[:, 0]
	n[:, 2] = m[:, 1]


	sudoku[3] =  np.concatenate((n[0], n[1], n[2]), axis=0 )
	sudoku[4] =  np.concatenate((n[2], n[0], n[1]), axis=0 )
	sudoku[5] =  np.concatenate((n[1], n[2], n[0]), axis=0 )

	l[:, 0] = n[:, 2]
	l[:, 1] = n[:, 0]
	l[:, 2] = n[:, 1]

	sudoku[6] =  np.concatenate((l[0], l[1], l[2]), axis=0 )
	sudoku[7] =  np.concatenate((l[2], l[0], l[1]), axis=0 )
	sudoku[8] =  np.concatenate((l[1], l[2], l[0]), axis=0 )

	return sudoku



#array_principal = [1,2,3,4,5,6,7,8,9]
#random.shuffle(array_principal);


array_principal = [4,9,2,3,5,7,8,1,6]

array_principal = np.array(array_principal)

m = array_principal.reshape(3,3)

sudoku = np.zeros((9,9), dtype=int)

sudoku = crear_sudoku(m)

print(sudoku)

