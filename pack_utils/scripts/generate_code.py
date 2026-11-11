import os
from itertools import permutations
import json

DIR_PATH = os.path.dirname(os.path.realpath(__file__))
OUT_PATH = f"{DIR_PATH}/../utils/"


def main_fork_nodes():
	with open(f"{DIR_PATH}/make_pack_node_mask_c.txt") as file:
		node_mask = file.read()
	with open(f"{DIR_PATH}/mask_for_nodes_c.txt") as file:
		for_loop_mask = file.read()
	for s in ('a', 'b'):
		for n in range(3, 7 if s=='b' else 6):
			d = set()
			for p in permutations(range(1, n+1)):
				for pos in range(n-2):
					func_name = f'make_pack_{n}{s}'
					if pos > 0:
						suffix = "".join(str(i) for i in p[:pos])
						func_name += f"_{suffix}"
					if func_name in d:
						continue
					d.add(func_name)
					sep = "" if pos > 0 else "_"
					for_loop_body = "".join(
						for_loop_mask.format(func_name=func_name, case=case, pos=pos, sep=sep)
						for case in p[pos:]
					)
					body = node_mask.format(for_loop_body=for_loop_body, func_name=func_name)
					with open(f"{OUT_PATH}/{func_name}.c", "w") as file:
						file.write(body)

def main_fork_results():
	with open(f"{DIR_PATH}/results.json") as file:
		data = json.load(file)
	with open(f"{DIR_PATH}/make_pack_leaf_mask_c.txt") as file:
		mask = file.read()

	lll = set()
	for prefix, perms in data.items():
		for perm, ops in perms.items():
			if len(perm) <= 2:
				continue
			func_name = f"make_pack_{prefix}_{perm[:-2]}"
			if (not func_name) or (func_name in lll):
				continue
			lll.add(func_name)
			case1 = perm[-2]
			case2 = perm[-1]
			out1 = ops
			perm = perm[:-2] + case2 + case1
			out2 = perms[perm]
			with open(f"{OUT_PATH}/{func_name}.c", "w") as file:
				file.write(mask.format(
					func_name=func_name, pos=len(perm)-2, case_1=case1, case_2=case2,
					out_1=out1, out_2=out2
				))

main_fork_nodes()
main_fork_results()
