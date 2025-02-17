class Node:
    def __init__(self, nameAr: str, nameEn: str, nameFr: str, univ: str):
        self.nameAr = nameAr
        self.nameEn = nameEn
        self.nameFr = nameFr
        self.univ = univ

    def getNameAr(self):
        return self.nameAr

    def getNameEn(self):
        return self.nameEn

    def getNameFr(self):
        return self.nameFr

    def getUniv(self):
        return self.univ
