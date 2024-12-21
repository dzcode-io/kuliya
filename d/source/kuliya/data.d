// This is an auto generated file, do not edit it!
module kuliya.data;

/++
Kuliya types
+/
enum Type
{
    UNIVERSITY,
    ACADEMY,
    PRIVATE_SCHOOL,
    INSTITUTE,
    FACULTY,
    DEPARTMENT,
    SPECIALTY,
    SECTOR
}

/++
Kuliya name
+/
struct Name
{
    /// Arabic name
    string ar;
    /// English name
    string en;
    /// French name
    string fr;
}

/++
Kuliya terms
+/
struct Terms
{
    /// Number of slots per year
    int perYear;
    /// Slots
    int[] slots;
}

/++
Kuliya schema
+/
struct Schema
{
    /// Name
    Name name;
    /// Type
    Type type;
    /// Terms
    Terms* terms;
}

static Schema umbm_fll_dfll = Schema(
    Name("قسم اللغة الفرنسية وآدابها", "Department of French Language and Literature", "Département de Langue et Littérature Françaises"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fll_dall = Schema(
    Name("قسم اللغة العربية وآدابها", "Department of Arabic Language and Literature", "Département de Langue et Littérature arabes"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fll_dell = Schema(
    Name("قسم اللغة الإنجليزية وآدابها", "Department of English Language and Literature", "Département de Langue et Littérature Anglaises"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fll = Schema(
    Name("كلية الآداب واللغات", "Faculty of Letters and Languages", "Faculté des Lettres et des Langues"),
    Type.FACULTY,
    null
);

static Schema umbm_fdsp = Schema(
    Name("كلية الحقوق والعلوم السياسية", "Faculty of Law and Political Sciences", "Faculté de Droit et Sciences Politiques"),
    Type.FACULTY,
    null
);

static Schema umbm_fdsp_ddroit = Schema(
    Name("قسم القانون", "Department of Law", "Département de Droit"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fdsp_dsp = Schema(
    Name("قسم العلوم السياسية", "Department of Political Science", "Département de Sciences Politiques"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_ftech_dhydr = Schema(
    Name("قسم الهيدروليكا", "Department of Hydraulics", "Département d'Hydraulique"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_ftech_dce = Schema(
    Name("قسم الهندسة المدنية", "Department of Civil Engineering", "Département de Génie Civil"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_ftech_dme = Schema(
    Name("قسم الهندسة الميكانيكية", "Department of Mecanical Engineering", "Département de Génie Mécanique"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_ftech_dee = Schema(
    Name("قسم الهندسة الكهربائية", "Department of Electrical Engineering", "Département de Génie Electrique"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_ftech_delec = Schema(
    Name("قسم الالكترونيات", "Department of Electronics", "Département d'Electronique"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_ftech = Schema(
    Name("كلية التكنولوجيا", "Faculty of Technology", "Faculté de Technologie"),
    Type.FACULTY,
    null
);

static Schema umbm_iutm_dcm = Schema(
    Name("قسم الاستشارات العلمية", "Department of Scientific Counsil", "Département du Conseil Scientifique"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_iutm_due = Schema(
    Name("قسم الهندسة الحضرية", "Department of Urban Engineering", "Département de Génie Urbain"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_iutm_dcg = Schema(
    Name("قسم الأرضية المشتركة", "Departement of common ground", "Département de terrain d'entente"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_iutm = Schema(
    Name("معهد إدارة التكنولوجيا الحضرية", "Urban Technology Management Institute", "Institut de Gestion des Technologies Urbaines"),
    Type.INSTITUTE,
    null
);

static Schema umbm_fsegc_dsfc = Schema(
    Name("قسم علوم المالية والمحاسبة", "Department of Finance and Accounting Sciences", "Département des Sciences Financières et Comptables"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fsegc_dsg = Schema(
    Name("قسم علوم التسيير", "Department of Management Sciences", "Département des Sciences de Gestion"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fsegc = Schema(
    Name("كلية العلوم الإقتصادية والتجارية وعلوم التسيير", "Faculty of Economics, Business and Management Sciences", "Faculté des Sciences économiques, Commerciales et de Gestion"),
    Type.FACULTY,
    null
);

static Schema umbm_fsegc_dse = Schema(
    Name("قسم العلوم الإقتصادية", "Department of Economic Sciences", "Département des Sciences économiques"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fsegc_dsc = Schema(
    Name("قسم العلوم التجارية", "Department of Commercial Sciences", "Département des Sciences Commerciales"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fmi_dcs = Schema(
    Name("قسم اﻹعلام اﻵلي", "Department of Computer Science", "Département Informatique"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fmi = Schema(
    Name("كلية الرياضيات و اﻹعلام اﻵلي", "Faculty of Mathematics and Computer Science", "Faculté des mathématiques et de l'informatique"),
    Type.FACULTY,
    null
);

static Schema umbm_fmi_dmath = Schema(
    Name("قسم الرياضيات", "Department of Mathematics", "Département des Mathématiques"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fshs_dhist = Schema(
    Name("قسم التاريخ", "Department of History", "Département d'Histoire"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fshs_dphilo = Schema(
    Name("قسم الفلسفة", "Department of Philosophy", "Département de Philosophie"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fshs_dsci = Schema(
    Name("قسم علوم الاعلام والاتصال", "Department of Information and Communication Sciences", "Département des Sciences de l'Information et de la Communication"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fshs_dsi = Schema(
    Name("قسم العلوم الإسلامية", "Department of Islamic Sciences", "Département des sciences islamiques"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fshs_dsocio = Schema(
    Name("قسم علم الاجتماع", "Department of Sociology", "Département de Sociologie"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fshs = Schema(
    Name("كلية العلوم الإنسانية والاجتماعية", "Faculty of Human Sciences and Social Sciences", "Faculté des sciences humaines et sociales"),
    Type.FACULTY,
    null
);

static Schema umbm_fsci_dchi = Schema(
    Name("قسم الكيمياء", "Department of Chemistry", "Département de Chimie"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fsci_dsa = Schema(
    Name("قسم علوم الأرغونوميك", "Department of Argonomic Sciences", "Département des Sciences Argonomiques"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fsci_dbcmb = Schema(
    Name("قسم الكيمياء الحيوية والأحياء الدقيقة", "Department of Biochemistry and Microbiology", "Département de Biochimie et de Microbiologie"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fsci_dphy = Schema(
    Name("قسم الفيزياء", "Department of Physics", "Département de Physique"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fsci_dsnv = Schema(
    Name("قسم علوم الطبيعة و الحياة", "Department of Natural and Life Sciences", "Département des Sciences de la Nature et de la Vie"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_fsci = Schema(
    Name("كلية العلوم", "Faculty of Sciences", "Faculté des sciences"),
    Type.FACULTY,
    null
);

static Schema umbm = Schema(
    Name("جامعة محمد بوضياف مسيلة", "University Mohamed Boudiaf M'sila", "Université Mohamed Boudiaf de M'Sila"),
    Type.UNIVERSITY,
    null
);

static Schema umbm_istaps_dags = Schema(
    Name("قسم الإدارة و التسيير الرياضي", "Department of Sports Administration and Management", "Département d'administration et de gestion des sports"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_istaps_dcbf = Schema(
    Name("قسم التكوين القاعدي المشترك", "Department of Common Basal Formation", "Département de Formation Basale Commune"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_istaps_dapsa = Schema(
    Name("قسم النشاط البدني و الرياضي المكيف", "Department of Adapted physical and sports activity", "Département d'Activité Physique et Sportive Adaptée"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_istaps_dfc = Schema(
    Name("قسم التدريب الرياضي", "Sports Training Department", "Département de la formation sportive"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_istaps_dep = Schema(
    Name("قسم التربية البدنية", "Department of Physical Education", "Département d'éducation Physique"),
    Type.DEPARTMENT,
    null
);

static Schema umbm_istaps = Schema(
    Name("معهد علوم وتقنيات النشاطات البدنية", "Institute of Sciences and Technologies of Physical Activities", "Institut des sciences et technologies des activités physiques"),
    Type.INSTITUTE,
    null
);

static Schema umbm_istaps_dmcs = Schema(
    Name("قسم الإعلام و الإتصال الرياضي", "Department of Media and Sports Communication", "Département des Médias et de la Communication Sportive"),
    Type.DEPARTMENT,
    null
);

static Schema umkb_fll = Schema(
    Name("كلية الآداب واللغات", "Faculty of Arts and Languages", "Faculté des Lettres et des Langues"),
    Type.FACULTY,
    null
);

static Schema umkb_fdsp = Schema(
    Name("كلية العلوم الاقتصادية والتجارية وعلوم التسيير", "Faculty of Law and Political Science", "Faculté de Droit et et des Sciences politiques"),
    Type.FACULTY,
    null
);

static Schema umkb_fsecsg = Schema(
    Name("كلية العلوم الاقتصادية والتجارية وعلوم التسيير", "Faculty of Economic, Commercial and Management Sciences", "Faculté des Sciences Economiques et Commerciales et des Sciences de Gestion"),
    Type.FACULTY,
    null
);

static Schema umkb_fshs = Schema(
    Name("كلية العلوم الانسانية و الاجتماعية", "Faculty of Humanities and Social Sciences", "Faculté des Sciences Humaines et Sociales"),
    Type.FACULTY,
    null
);

static Schema umkb_fsesnv = Schema(
    Name("كلية العلوم الدقيقة و علوم الطبيعة و الحياة", "Faculty of The Exact Sciences, Natural, and Life Sciences", "Faculté des Sciences Exactes, des Sciences de la nature et de la Vie"),
    Type.FACULTY,
    null
);

static Schema umkb = Schema(
    Name("جامعة محمد خيضر بسكرة", "University of Mohamed Khider Biskra", "Université Mohamed Khider Biskra"),
    Type.UNIVERSITY,
    null
);

static Schema umkb_fst_dee_sec = Schema(
    Name("تخصص التحكم الكهربائي", "Specialy of Electrical Control", "Spécialité de commande électrique"),
    Type.SPECIALTY,
    new Terms(2, [7, 8, 9, 10])
);

static Schema umkb_fst_dee = Schema(
    Name("قسم الهندسة كهربائية", "Department of Electrical Engeniering", "Departement de Génie Electrique"),
    Type.DEPARTMENT,
    null
);

static Schema umkb_fst = Schema(
    Name("كلية العلوم والتكنلوجيا", "Faculty of Science and Technology", "Faculté des Sciences et de la Technologie"),
    Type.FACULTY,
    null
);

static Schema umkb_istaps = Schema(
    Name("معهد علوم و تتقنيات النشاطات البدنية و الرياضية", "Institute of Sciences and Techniques of Physical Activities and Sports", "Institut des Sciences et Techniques des Activités Physiques et Sportives"),
    Type.INSTITUTE,
    null
);

static Schema usto_ieps = Schema(
    Name("معهد التربية البدنية والرياضة", "Institute Of Physical Education And Sport", "Institut d'éducation physique et de sport"),
    Type.INSTITUTE,
    null
);

static Schema usto_fch_dgc = Schema(
    Name("قسم الهندسة الكيميائية", "Departement of chemical engineering", "Déparetement Génie chimique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fch_dchm = Schema(
    Name("قسم كيمياء المواد", "Departement of Materials chemistry", "Déparetement Chimie des matériaux"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fch_dchp = Schema(
    Name("قسم الكيمياء الفيزيائية", "Departement of  Physical chemistry", "Déparetement Chimie physique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fch = Schema(
    Name("كلية الكيمياء", "Faculty of Chemistry", "Faculté de chimie"),
    Type.FACULTY,
    null
);

static Schema usto_ista = Schema(
    Name("معهد العلوم التطبيقية والتكنولوجيا", "Institute of Applied Science and Technology", "Institut des Sciences et Techniques Appliquées"),
    Type.INSTITUTE,
    null
);

static Schema usto_fmi_dinf = Schema(
    Name("قسم الرياضيات", "Departement of Mathematics", "Déparetement mathématiques"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fmi = Schema(
    Name("كلية الرياضيات و الاعلام الالي ", "Faculty  Mathematics and Computer Science", "Faculté des Mathématiques et Informatique"),
    Type.FACULTY,
    null
);

static Schema usto_fmi_dma = Schema(
    Name("قسم الاعلام الالي", "Departement of  Computer science", "Déparetement Informatique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fsnv_dbio = Schema(
    Name("قسم التكنولوجيا الحيوية", "Departement of Biotechnology", "Déparetement Biotechnologie"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fsnv_dve = Schema(
    Name("قسم الهندسة الفيزيائية", "Departement of physics Engineering ", "Déparetement Génie Phisique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fsnv_dgma = Schema(
    Name("قسم علم الوراثة الجزيئية التطبيقية", "Departement Applied Molecular Genetics", "Déparetement Génétique moléculaire appliquée"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fsnv = Schema(
    Name("قسم المعيشة والبيئة", "Departement of Living and environment", "Déparetement Vivant et environnement"),
    Type.FACULTY,
    null
);

static Schema usto = Schema(
    Name("جامعة وهران للعلوم و التكنولوجيا محمد بوضياف", "University of Sciences and Technology Oran Mohamed Boudiaf", "Université Des Sciences et de la Technologie Oran Mohamed Boudiaf"),
    Type.UNIVERSITY,
    null
);

static Schema usto_fag_da = Schema(
    Name("قسم العمارة", "Architecture department", "déparetement Architecture"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fag_dge = Schema(
    Name("كلية العمارة والهندسة المدنية", "Faculty of Architecture and Civil Engineering", "Faculté d'architecture et génie civil"),
    Type.FACULTY,
    null
);

static Schema usto_fag_dgc = Schema(
    Name("قسم الهندسة المدنية", "Civil engineering department", "Déparement Génie civil"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fag = Schema(
    Name("قسم هندسة المياه", "Water engineering department", "Déparement Génie de l'eau"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fge_dau = Schema(
    Name("قسم الإلكترونيات", "Department Automatic", "Department Automatique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fge_del = Schema(
    Name("قسم الهندسة الكهربائية", "Departement of Electrical engineering", "Déparetement Électrotechnique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fge = Schema(
    Name("كلية الهندسة الكهربائية", "Faculty of Electrical Engineering", "Faculté de génie électrique"),
    Type.FACULTY,
    null
);

static Schema usto_fge_delt = Schema(
    Name("قسم الهندسة الكهربائية", "Departement of Electrical engineering ", "Déparetement Électrotechnique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fgm_dgme = Schema(
    Name("قسم الهندسة الميكانيكية", "Department of Mechanical Engineering ", "Department Génie Mécanique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fgm_dmm = Schema(
    Name("قسم التعدين والمعادن", "Departement of Mining and Metallurgy", "Déparetement Mine et Métallurgie"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fgm_dgma = Schema(
    Name("قسم الهندسة البحرية", "Department of Marine Engineering", "Department Génie Maritime"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fgm = Schema(
    Name("كلية الهندسة الميكانيكية", "Faculty of Mechanical Engineering", "Faculté de génie mécanique"),
    Type.FACULTY,
    null
);

static Schema usto_fph_dgp = Schema(
    Name("قسم الهندسة الفيزيائية", "Departement of physics Engineering ", "Déparetement Génie Phisique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fph_dtm = Schema(
    Name("قسم الاعلام الالي", "Departement of  Computer science", "Déparetement Informatique"),
    Type.DEPARTMENT,
    null
);

static Schema usto_fph = Schema(
    Name("قسم تكنولوجيا المواد", "Faculty of Materials technology ", "Faculté Technologie des matériaux "),
    Type.DEPARTMENT,
    null
);

static Schema usto_fph_dpe = Schema(
    Name("قسم فيزياء الطاقة", "Departement of Physics energetics", "deparetement Physique énergétique"),
    Type.DEPARTMENT,
    null
);

static Schema ummto_fmed = Schema(
    Name("كلية الطب", "Faculty of Medicine", "Faculté de Médecine"),
    Type.FACULTY,
    null
);

static Schema ummto_fdsp = Schema(
    Name("كلية الحقوق والعلوم السياسية", "Faculty of Law and Political Sciences", "Faculté de Droit et des Sciences Politiques"),
    Type.FACULTY,
    null
);

static Schema ummto_fsecsg = Schema(
    Name("كلية الاقتصاد والأعمال وعلوم التسيير", "Faculty of Economics, Business and Management Sciences", "Faculté des Sciences Economiques, Commerciales et des Sciences de Gestion"),
    Type.FACULTY,
    null
);

static Schema ummto_fsbsa = Schema(
    Name("كلية العلوم البيولوجية والعلوم الزراعية", "Faculty of Biological Sciences and Agronomic Sciences", "Faculté des Sciences Biologiques et des Sciences Agronomiques"),
    Type.FACULTY,
    null
);

static Schema ummto_fshs = Schema(
    Name("كلية العلوم الإنسانية والاجتماعية", "Faculty of Humanities and Social Sciences", "Faculté des sciences humaines et sociales"),
    Type.FACULTY,
    null
);

static Schema ummto_dsat = Schema(
    Name("قسم العلوم التطبيقية والتقنيات", "Department of Applied Sciences and Technologies", "Département des Sciences Appliquée et des Technologies"),
    Type.DEPARTMENT,
    null
);

static Schema ummto_fgei = Schema(
    Name("كلية الهندسة الكهربائية وهندسة الإعلام الآلي", "Faculty of Electrical and Computer Engineering", "Faculté de Génie Electrique et Informatique"),
    Type.FACULTY,
    null
);

static Schema ummto = Schema(
    Name("جامعة مولود معمري", "University of Mouloud Mammeri", "Université Mouloud Mammeri"),
    Type.UNIVERSITY,
    null
);

static Schema ummto_dmi = Schema(
    Name("قسم الإعلام الآلي والرياضيات", "Mathematics - Computer Science Department", "Département Mathématiques - Informatique"),
    Type.DEPARTMENT,
    null
);

static Schema ummto_fgc = Schema(
    Name("كلية هندسة التشييد", "Faculty of Construction Engineering", "Faculté du Génie de la Construction"),
    Type.FACULTY,
    null
);

static Schema usthb_fgmgp_dcmp = Schema(
    Name("قسم الإنشاءات الميكانيكية والتصنيع", "Mechanical Construction and Manufacturing Department", "Département Construction Mécanique and Productique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fgmgp_dgcc = Schema(
    Name("قسم الهندسة الكيميائية وعلم التبريد", "Department of Chemical Engineering and Cryogenics", "Département Génie Chimique & Cryogénie"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fgmgp_dte = Schema(
    Name("قسم الطاقة الحرارية", "Thermo Energy Department", "Département Thermo Énergétique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fgmgp = Schema(
    Name("كلية الهندسة الميكانيكية وهندسة الطرائق", "Faculty of Mechanical Engineering and Process Engineering", "Faculté de Génie Mécanique et Génie de Procédés"),
    Type.FACULTY,
    null
);

static Schema usthb_fgmgp_dgegp = Schema(
    Name("قسم الهندسة البيئية والهندسة الصيدلانية", "Environmental Engineering and Pharmaceutical Engineering Department", "Département Génie Environnement & Génie Pharmaceutique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fgmgp_dsm = Schema(
    Name("قسم علوم المواد", "Department of Materials Sciences", "Département Sciences des Matériaux"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fsb_dee = Schema(
    Name("قسم البيئة", "Department of Ecology and Environment", "Département Écologie et Environnement"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fsb_dbcm = Schema(
    Name("قسم البيولوجيا الخلوية والجزيئية", "Cellular and Molecular Biology Department", "Département Biologie Cellulaire et Moléculaire"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fsb = Schema(
    Name("كلية العلوم البيولوجية", "Faculty of Biological Sciences", "Faculté des Sciences Biologiques"),
    Type.FACULTY,
    null
);

static Schema usthb_fsb_dbpo = Schema(
    Name("قسم علم الأحياء ووظائف الأعضاء", "Department of Biology and Physiology of Organisms", "Département Biologie et Physiologie des Organismes"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fchimie_dcpmi = Schema(
    Name("قسم كيمياء وفيزياء المواد غير العضوية", "Department of Chemistry and Physics of Inorganic Materials", "Département de Chimie et Physique des Matériaux Inorganique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fchimie_dcm = Schema(
    Name("قسم الكيمياء الجزيئية", "Department of Macromolecular Chemistry", "Département de Chimie Macromoleculaire"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fchimie_dcpt = Schema(
    Name("قسم الكيمياء الفيزيائية والنظرية", "Department of Physical and Theoretical Chemistry", "Département de Chimie Physique et Théorique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fchimie_dcoa = Schema(
    Name("قسم الكيمياء العضوية التطبيقية", "Department of Applied Organic Chemistry", "Département de Chimie Organique Appliquée"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fchimie = Schema(
    Name("كلية الكيمياء", "Faculty of Chemsitry", "Faculté de Chimie"),
    Type.FACULTY,
    null
);

static Schema usthb_fphy_demf = Schema(
    Name("قسم ميكانيكا الطاقة والموائع", "Department of Energy and Fluid Mechanics", "Département d’Energétique et Mécanique des Fluides"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fphy_dmc = Schema(
    Name("قسم المواد والمكونات", "Materials and Components Department", "Département Matériaux et Composant"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fphy_dpr = Schema(
    Name("قسم الفيزياء الإشعاعية", "Department of Radiation Physics", "Département de Physique des Rayonnements"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fphy_dpt = Schema(
    Name("قسم الفيزياء النظرية", "Department of Theoretical Physics", "Département de Physique Théorique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fphy = Schema(
    Name("كلية الفيزياء", "Faculty of Physics", "Faculté de Physique"),
    Type.FACULTY,
    null
);

static Schema usthb_fstgat_dgat = Schema(
    Name("قسم الجيوفيزياء", "Department of Geophysics", "Département de Géophysique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fstgat_dg = Schema(
    Name("قسم الجيولوجيا", "Department of Geology", "Département de Géologie"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fstgat_dgp = Schema(
    Name("قسم الجغرافيا والتخطيط الإقليمي", "Department of Geography and Regional Planning", "Département de Géographie et de l’Aménagement du Territoire"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fstgat = Schema(
    Name("كلية علوم اﻷرض و تهيئة اﻹقليم", "Faculty of Earth Sciences and Country Planning", "Faculté des Sciences de la terre et Aménagement du Territoire"),
    Type.FACULTY,
    null
);

static Schema usthb_fei_auto = Schema(
    Name("قسم الأجهزة والأتمتة", "Instrumentation and Automation Department", "Département Instrumentation et Automatique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fei_info = Schema(
    Name("قسم اﻹعلام اﻵلي", "Department of Computer Science", "Département Informatique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fei_telecom = Schema(
    Name("قسم اﻹتصال", "Telecommunications Department", "Département Télécommunication"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fei = Schema(
    Name("كلية اﻹلكترونيك و اﻹعلام اﻵلي", "Faculty of Electronics and Computer Science", "Faculté d’Electronique et d’Informatique"),
    Type.FACULTY,
    null
);

static Schema usthb_fei_elt = Schema(
    Name("قسم اﻹلكترونيك", "Department of Electronics", "Département Electrotechnique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb = Schema(
    Name("جامعة هواري بومدين للعلوم والتكنولوجيا", "University of Sciences and Technology Houari Boumediene", "Université Des Sciences et de la Technologie Houari Boumediene"),
    Type.UNIVERSITY,
    null
);

static Schema usthb_fmath_da = Schema(
    Name("قسم التحليل", "Analysis Department", "Département Analyse"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fmath_dps = Schema(
    Name("قسم الاحتمالات والإحصاء", "Probability and Statistics Department", "Département Probabilités et statistiques"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fmath_dro = Schema(
    Name("قسم البحوث التشغيلية", "Operational Research Department", "Département Recherche Opérationnelle"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fmath = Schema(
    Name("كلية الرياضيات", "Faculty of Mathematics", "Faculté de Mathématiques"),
    Type.FACULTY,
    null
);

static Schema usthb_fmath_datn = Schema(
    Name("قسم الجبر ونظرية الأعداد", "Department of Algebra and Number Theory", "Département Algèbre et théorie des nombres"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fgc = Schema(
    Name("كلية الهندسة المدنية", "Faculty of Civil Engineering", "Faculté de Génie Civil"),
    Type.FACULTY,
    null
);

static Schema usthb_fgc_dgh = Schema(
    Name("قسم الجيوتكنيك والهيدروليكا", "Department of Geotechnics and Hydraulics", "Département de Géotechnique et Hydraulique"),
    Type.DEPARTMENT,
    null
);

static Schema usthb_fgc_dsm = Schema(
    Name("قسم الهياكل والمواد", "Department of Structures and Materials", "Département de Structures et Matérieux"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facdr_pld = Schema(
    Name("قسم القانون العام", "Public Law Department", "Département De Droit Public"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facdr_psd = Schema(
    Name("قسم العلوم السياسية", "Political Sciences Department", "Département Des Sciences Politiques"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facdr = Schema(
    Name("كلية الحقوق", "Faculty Of Law", "Faculté De Droit"),
    Type.FACULTY,
    null
);

static Schema ubma_facsc_pd = Schema(
    Name("قسم الفلسفة", "Physics Department", "Département De Philosophie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsc_ssd = Schema(
    Name("قسم علوم البحار", "Sea Sciences Department", "Département Des Sciences De La Mer"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsc_nlsd = Schema(
    Name("قسم علوم الطبيعة والحياة", "Nature And Life Sciences Department", "Département Nature Et Sciences De La Vie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsc_bd = Schema(
    Name("قسم علم المكتبيات", "Biology Department", "Département Biblitheconomy"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsc_mcd = Schema(
    Name("قسم الرياضيات و الإعلام الألي", "Mathematics And Computing Department", "Département Mathématiques Et Informatique"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsc_md = Schema(
    Name("قسم الرياضيات", "Mathematics Department", "Département De Mathématiques"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsc_msd = Schema(
    Name("قسم العلوم الإدارية", "Material Sciences Department", "Département Des Sciences De Gestion"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsc = Schema(
    Name("كلية العلوم", "Faculty Of Sciences", "Faculté Des Sciences"),
    Type.FACULTY,
    null
);

static Schema ubma_facsc_cd = Schema(
    Name("قسم الكيمياء", "Chemistry Department", "Département De Chimie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facscm_pd = Schema(
    Name("قسم الصيدلة", "Pharmacy Department", "Département de Pharmacie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facscm_ddm = Schema(
    Name("قسم طب الأسنان", "Department Of Dental Medicine", "Département De Médecine Dentaire"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facscm_md = Schema(
    Name("قسم الطب", "Medicine Department", "Département De Mathématiques"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facscm = Schema(
    Name("كلية العلوم الطبية", "Faculty Of Medical Sciences", "Faculté Des Sciences Médicales"),
    Type.FACULTY,
    null
);

static Schema ubma_facscm_tt = Schema(
    Name("", "Teacher Training", ""),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_pd = Schema(
    Name("قسم الفلسفة", "Philosophy Department", "Département De Philosophie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_alld = Schema(
    Name("قسم اللغة العربية وآدابها", "Arabic Language And Literature Department", "Département De Langue Et Littérature Arabes"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_sd = Schema(
    Name("قسم الاجتماع", "Sociology Department", "Département De Sociologie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_icsd = Schema(
    Name("قسم علوم الإعلام والاتصال", "Information And Communication Sciences Department", "Département Des Sciences De L'Information Et De La Communication"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_fld = Schema(
    Name("قسم اللغة الفرنسية", "French Language Department", "Département De Langue Française"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_hd = Schema(
    Name("قسم التاريخ", "History Department", "Département D'Histoire"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_bd = Schema(
    Name("قسم علم المكتبيات", "Biblitheconomy Department", "Département Biblitheconomy"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_eld = Schema(
    Name("قسم اللغة الإنجليزية", "English Language Department", "Département De Langue Anglaise"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_td = Schema(
    Name("قسم الترجمة", "Translation Department", "Service De Traduction"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_hssd = Schema(
    Name("قسم العلوم الإنسانية والاجتماعية", "Human And Social Sciences Department", "Département Des Sciences Humaines Et Sociales"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs = Schema(
    Name("كلية الآداب والعلوم الإنسانية والاجتماعية", "Faculty Of Letters, Humanities And Social Sciences", "Faculté Des Lettres, Sciences Humaines Et Sociales"),
    Type.FACULTY,
    null
);

static Schema ubma_faclschs_psed = Schema(
    Name("قسم التربية البدنية والرياضية", "Physical And Sports Education Department", "Service D'Éducation Physique Et Sportive"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_faclschs_ild = Schema(
    Name("قسم اللغة الإيطالية", "Italian Language Department", "Département De Langue Italienne"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsceg_esd = Schema(
    Name("قسم العلوم الاقتصادية", "Economic Sciences Department", "Département Des Sciences Économiques"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsceg_ct = Schema(
    Name("جذع مشترك", "Common Trunk", "Tronc Commun"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsceg_fsd = Schema(
    Name("قسم العلوم المالية", "Financial Sciences Department", "Département Des Sciences Financières"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsceg_msd = Schema(
    Name("قسم العلوم الإدارية", "Management Sciences Department", "Département Des Sciences De Gestion"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsceg = Schema(
    Name("كلية الاقتصاد وعلوم التسيير", "Faculty Of Economics And Management Sciences", "Faculté Des Sciences Économiques Et De Gestion"),
    Type.FACULTY,
    null
);

static Schema ubma_facsct_pd = Schema(
    Name("قسم التخطيط", "Planning Department", "Département de la Planification"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsct_ad = Schema(
    Name("قسم العمارة", "Architecture Department", "Département D'Architecture"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsct_md = Schema(
    Name("قسم التعدين", "Mining Department", "Département des Mines"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsct = Schema(
    Name("كلية علوم الأرض", "Faculty Of Earth Sciences", "Faculté Des Sciences De La Terre"),
    Type.FACULTY,
    null
);

static Schema ubma_facsct_gd = Schema(
    Name("قسم الجيولوجيا", "Geology Department", "Département De Géologie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_ped = Schema(
    Name("قسم هندسة العمليات", "Process Engineering Department", "Département Génie Des Procédés"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_hd = Schema(
    Name("قسم الهيدروليك", "Hydraulic Department", "Département Hydraulique"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_ed = Schema(
    Name("القسم الكهروتقني", "Electrotechnical Department", "Département Électrotechnique"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_std = Schema(
    Name("قسم العلوم والتكنولوجيا", "Science And Technology Department", "Département Des Sciences Et De La Technologie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_csd = Schema(
    Name("قسم الإعلام الألي", "Computer Science Department", "Département Informatique"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_md = Schema(
    Name("قسم علم المعادن", "Metalurgy Department", "Département Métallurgie"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci = Schema(
    Name("كلية العلوم الهندسية", "Faculty Of Engineering Sciences", "Faculté Des Sciences De L'Ingénieur"),
    Type.FACULTY,
    null
);

static Schema ubma_facsci_tt = Schema(
    Name("", "Teacher Training", ""),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_ced = Schema(
    Name("قسم الهندسة المدنية", "Civil Engineering Department", "Département Génie Civil"),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_d = Schema(
    Name("", "Doctorat", ""),
    Type.DEPARTMENT,
    null
);

static Schema ubma_facsci_med = Schema(
    Name("قسم الهندسة الميكانيكية", "Mechanical Engineering Department", "Département de Génie Mécanique"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fle_dfr = Schema(
    Name("قسم اللغة الفرنسية ", "Department of French", "Département de Langue Française"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fle_dsgi = Schema(
    Name("قسم اللغات الاسبانية , الألمانية , الايطالية  ", "Department of Spanish, German & Italian", "Département des Langues Espagnole, Allemande, et Italienne"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fle_den = Schema(
    Name("قسم اللغة الانجليزية ", "Department of English", "Département de Langue Anglaise"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fle = Schema(
    Name("كلية العلوم الإنسانية", "Faculty of Humanities", "Faculté des Sciences Humaines"),
    Type.FACULTY,
    null
);

static Schema ua2aks_it = Schema(
    Name("معهد الآثار", "Institute of archology", "Institut d’archéologie"),
    Type.INSTITUTE,
    null
);

static Schema ua2aks_ia = Schema(
    Name("معهد الترجمة", "Institute of translation", "Institut de traduction"),
    Type.INSTITUTE,
    null
);

static Schema ua2aks = Schema(
    Name("جامعة الجزائر 2  أبو القاسم سعد الله", "University of Algiers 2 Abou El-kacem Saâdallah", "Université d’Alger 2 Abou El Kacem Saâdallah"),
    Type.UNIVERSITY,
    null
);

static Schema ua2aks_fss_dedu = Schema(
    Name("قسم علوم التربية", "Department of educational sciences", "Département de sciences de l’éducation"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fss_dpsy = Schema(
    Name("قسم علم النفس", "Department of psychology", "Département de psychologie"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fss_dst = Schema(
    Name("قسم الأرطوفونيا", "Department of speech therapy", "Département d'orthophonie"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fss_dsocio = Schema(
    Name("قسم علم الاجتماع", "Department of sociology", "Département de sociologie"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fss = Schema(
    Name("كلية العلوم الإنسانية", "Faculty of humanities", "Faculté des sciences humaines"),
    Type.FACULTY,
    null
);

static Schema ua2aks_fsh_dh = Schema(
    Name("قسم الفلسفة", "Department of philosophy", "Département de philosophie"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fsh_dph = Schema(
    Name("قسم التاريخ", "Department of history", "Département d'اhistoire"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fsh_dld = Schema(
    Name("قسم علم المكتبات والتوثيق", "Department of librarianship and documentation", "Département de bibliothéconomie"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_fsh = Schema(
    Name("كلية العلوم الإنسانية", "Faculty of Humanities", "Faculté des Sciences Humaines"),
    Type.FACULTY,
    null
);

static Schema ua2aks_falaol_dts = Schema(
    Name("قسم علوم اللسان ", "Department of Tongue Sciences", "Département des Sciences du Langage"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_falaol_dart = Schema(
    Name("قسم الفنون ", "Department of Arts", "Département des Arts"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_falaol_dtrl = Schema(
    Name("قسم اللغة التركية والروسية ", "Department of Turkish and Russian Languages", "Département de langues Turque et Russe"),
    Type.DEPARTMENT,
    null
);

static Schema ua2aks_falaol = Schema(
    Name("كلية العلوم الإنسانية", "Faculty of Humanities", "Faculté des Sciences Humaines"),
    Type.FACULTY,
    null
);

static Schema ua2aks_falaol_dala = Schema(
    Name("قسم اللغة العربية وآدابها ", "Department of Arabic Language and Arts", "Département de Langue et Lettres arabes et Langues Orientales"),
    Type.DEPARTMENT,
    null
);

/++
Get node by path
Params:
    path = Path of the node
Returns:
    Schema
+/
Schema* _getNodeByPath(string path)
{
    switch (path)
    {
        case "umbm/fll/dfll":
            return &umbm_fll_dfll;
        case "umbm/fll/dall":
            return &umbm_fll_dall;
        case "umbm/fll/dell":
            return &umbm_fll_dell;
        case "umbm/fll":
            return &umbm_fll;
        case "umbm/fdsp":
            return &umbm_fdsp;
        case "umbm/fdsp/ddroit":
            return &umbm_fdsp_ddroit;
        case "umbm/fdsp/dsp":
            return &umbm_fdsp_dsp;
        case "umbm/ftech/dhydr":
            return &umbm_ftech_dhydr;
        case "umbm/ftech/dce":
            return &umbm_ftech_dce;
        case "umbm/ftech/dme":
            return &umbm_ftech_dme;
        case "umbm/ftech/dee":
            return &umbm_ftech_dee;
        case "umbm/ftech/delec":
            return &umbm_ftech_delec;
        case "umbm/ftech":
            return &umbm_ftech;
        case "umbm/iutm/dcm":
            return &umbm_iutm_dcm;
        case "umbm/iutm/due":
            return &umbm_iutm_due;
        case "umbm/iutm/dcg":
            return &umbm_iutm_dcg;
        case "umbm/iutm":
            return &umbm_iutm;
        case "umbm/fsegc/dsfc":
            return &umbm_fsegc_dsfc;
        case "umbm/fsegc/dsg":
            return &umbm_fsegc_dsg;
        case "umbm/fsegc":
            return &umbm_fsegc;
        case "umbm/fsegc/dse":
            return &umbm_fsegc_dse;
        case "umbm/fsegc/dsc":
            return &umbm_fsegc_dsc;
        case "umbm/fmi/dcs":
            return &umbm_fmi_dcs;
        case "umbm/fmi":
            return &umbm_fmi;
        case "umbm/fmi/dmath":
            return &umbm_fmi_dmath;
        case "umbm/fshs/dhist":
            return &umbm_fshs_dhist;
        case "umbm/fshs/dphilo":
            return &umbm_fshs_dphilo;
        case "umbm/fshs/dsci":
            return &umbm_fshs_dsci;
        case "umbm/fshs/dsi":
            return &umbm_fshs_dsi;
        case "umbm/fshs/dsocio":
            return &umbm_fshs_dsocio;
        case "umbm/fshs":
            return &umbm_fshs;
        case "umbm/fsci/dchi":
            return &umbm_fsci_dchi;
        case "umbm/fsci/dsa":
            return &umbm_fsci_dsa;
        case "umbm/fsci/dbcmb":
            return &umbm_fsci_dbcmb;
        case "umbm/fsci/dphy":
            return &umbm_fsci_dphy;
        case "umbm/fsci/dsnv":
            return &umbm_fsci_dsnv;
        case "umbm/fsci":
            return &umbm_fsci;
        case "umbm":
            return &umbm;
        case "umbm/istaps/dags":
            return &umbm_istaps_dags;
        case "umbm/istaps/dcbf":
            return &umbm_istaps_dcbf;
        case "umbm/istaps/dapsa":
            return &umbm_istaps_dapsa;
        case "umbm/istaps/dfc":
            return &umbm_istaps_dfc;
        case "umbm/istaps/dep":
            return &umbm_istaps_dep;
        case "umbm/istaps":
            return &umbm_istaps;
        case "umbm/istaps/dmcs":
            return &umbm_istaps_dmcs;
        case "umkb/fll":
            return &umkb_fll;
        case "umkb/fdsp":
            return &umkb_fdsp;
        case "umkb/fsecsg":
            return &umkb_fsecsg;
        case "umkb/fshs":
            return &umkb_fshs;
        case "umkb/fsesnv":
            return &umkb_fsesnv;
        case "umkb":
            return &umkb;
        case "umkb/fst/dee/sec":
            return &umkb_fst_dee_sec;
        case "umkb/fst/dee":
            return &umkb_fst_dee;
        case "umkb/fst":
            return &umkb_fst;
        case "umkb/istaps":
            return &umkb_istaps;
        case "usto/ieps":
            return &usto_ieps;
        case "usto/fch/dgc":
            return &usto_fch_dgc;
        case "usto/fch/dchm":
            return &usto_fch_dchm;
        case "usto/fch/dchp":
            return &usto_fch_dchp;
        case "usto/fch":
            return &usto_fch;
        case "usto/ista":
            return &usto_ista;
        case "usto/fmi/dinf":
            return &usto_fmi_dinf;
        case "usto/fmi":
            return &usto_fmi;
        case "usto/fmi/dma":
            return &usto_fmi_dma;
        case "usto/fsnv/dbio":
            return &usto_fsnv_dbio;
        case "usto/fsnv/dve":
            return &usto_fsnv_dve;
        case "usto/fsnv/dgma":
            return &usto_fsnv_dgma;
        case "usto/fsnv":
            return &usto_fsnv;
        case "usto":
            return &usto;
        case "usto/fag/da":
            return &usto_fag_da;
        case "usto/fag/dge":
            return &usto_fag_dge;
        case "usto/fag/dgc":
            return &usto_fag_dgc;
        case "usto/fag":
            return &usto_fag;
        case "usto/fge/dau":
            return &usto_fge_dau;
        case "usto/fge/del":
            return &usto_fge_del;
        case "usto/fge":
            return &usto_fge;
        case "usto/fge/delt":
            return &usto_fge_delt;
        case "usto/fgm/dgme":
            return &usto_fgm_dgme;
        case "usto/fgm/dmm":
            return &usto_fgm_dmm;
        case "usto/fgm/dgma":
            return &usto_fgm_dgma;
        case "usto/fgm":
            return &usto_fgm;
        case "usto/fph/dgp":
            return &usto_fph_dgp;
        case "usto/fph/dtm":
            return &usto_fph_dtm;
        case "usto/fph":
            return &usto_fph;
        case "usto/fph/dpe":
            return &usto_fph_dpe;
        case "ummto/fmed":
            return &ummto_fmed;
        case "ummto/fdsp":
            return &ummto_fdsp;
        case "ummto/fsecsg":
            return &ummto_fsecsg;
        case "ummto/fsbsa":
            return &ummto_fsbsa;
        case "ummto/fshs":
            return &ummto_fshs;
        case "ummto/dsat":
            return &ummto_dsat;
        case "ummto/fgei":
            return &ummto_fgei;
        case "ummto":
            return &ummto;
        case "ummto/dmi":
            return &ummto_dmi;
        case "ummto/fgc":
            return &ummto_fgc;
        case "usthb/fgmgp/dcmp":
            return &usthb_fgmgp_dcmp;
        case "usthb/fgmgp/dgcc":
            return &usthb_fgmgp_dgcc;
        case "usthb/fgmgp/dte":
            return &usthb_fgmgp_dte;
        case "usthb/fgmgp":
            return &usthb_fgmgp;
        case "usthb/fgmgp/dgegp":
            return &usthb_fgmgp_dgegp;
        case "usthb/fgmgp/dsm":
            return &usthb_fgmgp_dsm;
        case "usthb/fsb/dee":
            return &usthb_fsb_dee;
        case "usthb/fsb/dbcm":
            return &usthb_fsb_dbcm;
        case "usthb/fsb":
            return &usthb_fsb;
        case "usthb/fsb/dbpo":
            return &usthb_fsb_dbpo;
        case "usthb/fchimie/dcpmi":
            return &usthb_fchimie_dcpmi;
        case "usthb/fchimie/dcm":
            return &usthb_fchimie_dcm;
        case "usthb/fchimie/dcpt":
            return &usthb_fchimie_dcpt;
        case "usthb/fchimie/dcoa":
            return &usthb_fchimie_dcoa;
        case "usthb/fchimie":
            return &usthb_fchimie;
        case "usthb/fphy/demf":
            return &usthb_fphy_demf;
        case "usthb/fphy/dmc":
            return &usthb_fphy_dmc;
        case "usthb/fphy/dpr":
            return &usthb_fphy_dpr;
        case "usthb/fphy/dpt":
            return &usthb_fphy_dpt;
        case "usthb/fphy":
            return &usthb_fphy;
        case "usthb/fstgat/dgat":
            return &usthb_fstgat_dgat;
        case "usthb/fstgat/dg":
            return &usthb_fstgat_dg;
        case "usthb/fstgat/dgp":
            return &usthb_fstgat_dgp;
        case "usthb/fstgat":
            return &usthb_fstgat;
        case "usthb/fei/auto":
            return &usthb_fei_auto;
        case "usthb/fei/info":
            return &usthb_fei_info;
        case "usthb/fei/telecom":
            return &usthb_fei_telecom;
        case "usthb/fei":
            return &usthb_fei;
        case "usthb/fei/elt":
            return &usthb_fei_elt;
        case "usthb":
            return &usthb;
        case "usthb/fmath/da":
            return &usthb_fmath_da;
        case "usthb/fmath/dps":
            return &usthb_fmath_dps;
        case "usthb/fmath/dro":
            return &usthb_fmath_dro;
        case "usthb/fmath":
            return &usthb_fmath;
        case "usthb/fmath/datn":
            return &usthb_fmath_datn;
        case "usthb/fgc":
            return &usthb_fgc;
        case "usthb/fgc/dgh":
            return &usthb_fgc_dgh;
        case "usthb/fgc/dsm":
            return &usthb_fgc_dsm;
        case "ubma/facdr/pld":
            return &ubma_facdr_pld;
        case "ubma/facdr/psd":
            return &ubma_facdr_psd;
        case "ubma/facdr":
            return &ubma_facdr;
        case "ubma/facsc/pd":
            return &ubma_facsc_pd;
        case "ubma/facsc/ssd":
            return &ubma_facsc_ssd;
        case "ubma/facsc/nlsd":
            return &ubma_facsc_nlsd;
        case "ubma/facsc/bd":
            return &ubma_facsc_bd;
        case "ubma/facsc/mcd":
            return &ubma_facsc_mcd;
        case "ubma/facsc/md":
            return &ubma_facsc_md;
        case "ubma/facsc/msd":
            return &ubma_facsc_msd;
        case "ubma/facsc":
            return &ubma_facsc;
        case "ubma/facsc/cd":
            return &ubma_facsc_cd;
        case "ubma/facscm/pd":
            return &ubma_facscm_pd;
        case "ubma/facscm/ddm":
            return &ubma_facscm_ddm;
        case "ubma/facscm/md":
            return &ubma_facscm_md;
        case "ubma/facscm":
            return &ubma_facscm;
        case "ubma/facscm/tt":
            return &ubma_facscm_tt;
        case "ubma/faclschs/pd":
            return &ubma_faclschs_pd;
        case "ubma/faclschs/alld":
            return &ubma_faclschs_alld;
        case "ubma/faclschs/sd":
            return &ubma_faclschs_sd;
        case "ubma/faclschs/icsd":
            return &ubma_faclschs_icsd;
        case "ubma/faclschs/fld":
            return &ubma_faclschs_fld;
        case "ubma/faclschs/hd":
            return &ubma_faclschs_hd;
        case "ubma/faclschs/bd":
            return &ubma_faclschs_bd;
        case "ubma/faclschs/eld":
            return &ubma_faclschs_eld;
        case "ubma/faclschs/td":
            return &ubma_faclschs_td;
        case "ubma/faclschs/hssd":
            return &ubma_faclschs_hssd;
        case "ubma/faclschs":
            return &ubma_faclschs;
        case "ubma/faclschs/psed":
            return &ubma_faclschs_psed;
        case "ubma/faclschs/ild":
            return &ubma_faclschs_ild;
        case "ubma/facsceg/esd":
            return &ubma_facsceg_esd;
        case "ubma/facsceg/ct":
            return &ubma_facsceg_ct;
        case "ubma/facsceg/fsd":
            return &ubma_facsceg_fsd;
        case "ubma/facsceg/msd":
            return &ubma_facsceg_msd;
        case "ubma/facsceg":
            return &ubma_facsceg;
        case "ubma/facsct/pd":
            return &ubma_facsct_pd;
        case "ubma/facsct/ad":
            return &ubma_facsct_ad;
        case "ubma/facsct/md":
            return &ubma_facsct_md;
        case "ubma/facsct":
            return &ubma_facsct;
        case "ubma/facsct/gd":
            return &ubma_facsct_gd;
        case "ubma/facsci/ped":
            return &ubma_facsci_ped;
        case "ubma/facsci/hd":
            return &ubma_facsci_hd;
        case "ubma/facsci/ed":
            return &ubma_facsci_ed;
        case "ubma/facsci/std":
            return &ubma_facsci_std;
        case "ubma/facsci/csd":
            return &ubma_facsci_csd;
        case "ubma/facsci/md":
            return &ubma_facsci_md;
        case "ubma/facsci":
            return &ubma_facsci;
        case "ubma/facsci/tt":
            return &ubma_facsci_tt;
        case "ubma/facsci/ced":
            return &ubma_facsci_ced;
        case "ubma/facsci/d":
            return &ubma_facsci_d;
        case "ubma/facsci/med":
            return &ubma_facsci_med;
        case "ua2aks/fle/dfr":
            return &ua2aks_fle_dfr;
        case "ua2aks/fle/dsgi":
            return &ua2aks_fle_dsgi;
        case "ua2aks/fle/den":
            return &ua2aks_fle_den;
        case "ua2aks/fle":
            return &ua2aks_fle;
        case "ua2aks/it":
            return &ua2aks_it;
        case "ua2aks/ia":
            return &ua2aks_ia;
        case "ua2aks":
            return &ua2aks;
        case "ua2aks/fss/dedu":
            return &ua2aks_fss_dedu;
        case "ua2aks/fss/dpsy":
            return &ua2aks_fss_dpsy;
        case "ua2aks/fss/dst":
            return &ua2aks_fss_dst;
        case "ua2aks/fss/dsocio":
            return &ua2aks_fss_dsocio;
        case "ua2aks/fss":
            return &ua2aks_fss;
        case "ua2aks/fsh/dh":
            return &ua2aks_fsh_dh;
        case "ua2aks/fsh/dph":
            return &ua2aks_fsh_dph;
        case "ua2aks/fsh/dld":
            return &ua2aks_fsh_dld;
        case "ua2aks/fsh":
            return &ua2aks_fsh;
        case "ua2aks/falaol/dts":
            return &ua2aks_falaol_dts;
        case "ua2aks/falaol/dart":
            return &ua2aks_falaol_dart;
        case "ua2aks/falaol/dtrl":
            return &ua2aks_falaol_dtrl;
        case "ua2aks/falaol":
            return &ua2aks_falaol;
        case "ua2aks/falaol/dala":
            return &ua2aks_falaol_dala;
        default:
            return null;
    }
}

