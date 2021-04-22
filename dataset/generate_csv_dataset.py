import csv
from faker import Faker

amount_samples = [100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 2500000, 5000000]
folders = ['tree_creation/data_1/',
           'tree_creation/data_2/',
           'tree_creation/data_3/',
           'tree_creation/data_4/', 'tree_creation/data_5/', 'tree_creation/data_6/',
           'tree_creation/data_7/', 'tree_creation/data_8/', 'tree_creation/data_9/',
           'tree_creation/data_10/']
files = ['100.csv', '500.csv', '1000.csv', '5000.csv', '10000csv', '25000.csv', '50000.csv', '100000csv', '250000.csv',
         '500000.csv', '750000.csv', '1000000.csv']

# To generate only certain dataset or certain quantity of data just exclude not needed files from the list above
if __name__ == '__main__':
    fake = Faker()

    for folder in folders:
        for file, j in zip(files, amount_samples):
            with open(folder + file, 'w', newline='') as csvfile:
                spamwriter = csv.writer(csvfile, delimiter=' ',
                                        quotechar='|', quoting=csv.QUOTE_MINIMAL)
                spamwriter.writerow([fake.pystr(max_chars=j)])
