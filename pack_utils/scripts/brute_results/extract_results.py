from collections import defaultdict
from glob import glob
import json
import os
import re

dir_path = os.path.dirname(os.path.realpath(__file__))

def nested_dict():
	return defaultdict(nested_dict)

def default_nested_dict(iterable):
	return defaultdict(nested_dict, iterable)

PATTERN_NAME = re.compile(r".*(?P<n>\d)_(?P<s>A|B).txt")

PATTERN_LINE = re.compile(r"^\d, \((?P<label>[\d, ]+)\), \[(?P<ops>(([a-z]+)|.)+)\]$")

files = glob("**/results*.txt", recursive=True)

data = nested_dict()

for filename in files:
	match = PATTERN_NAME.match(filename)
	if match is None:
		continue
	entry = data[match['n'] + match['s'].lower()]
	with open(filename) as file:
		for line in file:
			match = PATTERN_LINE.match(line)
			label = "".join(re.findall(r'\d', match.group('label')))
			ops = re.findall(r'[a-z]+', match.group('ops'))
			entry[label] = ",".join(ops)

with open(f"{dir_path}/results.json", "w") as file:
	json.dump(data, file)
