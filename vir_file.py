import os,pickle,hashlib

def getHash(path, blocksize=65536):
    afile = open(path, 'rb')
    hasher = hashlib.md5()
    buf = afile.read(blocksize)
    while len(buf) > 0:
        hasher.update(buf)
        buf = afile.read(blocksize)
    afile.close()
    return hasher.hexdigest()


def create_file_list(root):
    ret_list = []
    for path, dirs, files in os.walk(root) :
        for file in files :
            ext = os.path.splitext(file)[-1]
            if ext == '.vir':
                ret_list.append(os.path.join(path, file))

    for i in ret_list:
        if not os.path.exists(os.path.basename(os.path.dirname(i)) + '.pickle'):
            f = open(i, 'rb')
            fileHash = getHash(i)
            with open(os.path.basename(os.path.dirname(i)) + '.pickle', 'wb') as f:
                pickle.dump(fileHash, f)
            f.close()

    return ret_list


if __name__ == '__main__' :
    path = os.path.normpath(os.path.abspath('./dataset'))
    path_list = create_file_list(path)
