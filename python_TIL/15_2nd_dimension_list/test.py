"""
rtio = [0.02469, 0.00368, 0.01384, 0.04322, -0.02706, -0.02215, 0.02993, -0.00353, 0.00355, 0.03639, -0.00707, -0.02340, -0.00495, -0.01322, 0.04046, -0.01198, 0.03019, 0.00000, -0.01528, -0.02468, -0.00117, -0.00601, 0.00131, 0.03135]
ast = 1000000
for i in rtio:
	ast = ast + ast * i
	print(ast)
"""

import pandas as pd

df = pd.read_csv("/Users/choewonjun/Documents/Untitled Folder/stock.csv")
rtio = df[df['stck_itmt_nm'] == 'KODEX 200']['dy_aset_sepr_prft_rt']
print(rtio)
