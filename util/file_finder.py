import os,pickle,hashlib


def create_file_list(root):
    ret_list = []
    for path, dirs, files in os.walk(root) :
        for file in files :
            ext = os.path.splitext(file)[-1]
            if ext == '.txt':
                ret_list.append(os.path.join(path, file))

    for i in ret_list:
        if not os.path.exists(os.path.basename(os.path.dirname(i)) + '.pickle'):
            files = open(i, 'rb')
            data = files.read()
            md5_data = hashlib.md5(data).hexdigest()
            with open(os.path.basename(os.path.dirname(i)) + '.pickle', 'wb') as f:
                pickle.dump(md5_data, f)
            f.close()


if __name__ == '__main__' :
    path = os.path.normpath(os.path.abspath('./dataset'))
    create_file_list(path)
