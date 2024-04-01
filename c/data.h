// This is an auto generated file, do not edit it!
#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <string.h>

#define STR_EQ(str1, str2) (strcmp(str1, str2) == 0)

/**
 * Node type.
 */
typedef enum
{
	/** University. */
	UNIVERSITY,
	/** Academy. */
	ACADEMY,
	/** Private school. */
	PRIVATE_SCHOOL,
	/** Institute */
	INSTITUTE,
	/** Faculty */
	FACULTY,
	/** Department */
	DEPARTMENT,
	/** Specialty. */
	SPECIALTY,
	/** Sector. */
	SECTOR
} node_type;

/**
 * Kuliya names in Arabic, English and French.
 */
typedef struct
{
	/** Arabic name. */
	const char *ar;
	/** English name. */
	const char *en;
	/** French name. */
	const char *fr;
} kuliya_name;

/**
 * Kuliya terms.
 */
typedef struct
{
	/** Slots per year. */
	int per_year;
	/** Slots. */
	int *slots;
	/** Number of slots. */
	size_t number_of_slots;
} kuliya_terms;

/**
 * Kuliya schema.
 */
typedef struct
{
	/** Name. */
	kuliya_name name;
	/** Node type. */
	node_type type;
	/** Terms. */
	kuliya_terms *terms;
} kuliya_schema;

static kuliya_schema umbm = {.name = {.ar = "جامعة محمد بوضياف مسيلة", .en = "University Mohamed Boudiaf M'sila", .fr = "Université Mohamed Boudiaf de M'Sila"}, .type = UNIVERSITY, .terms = NULL};
static kuliya_schema umbm_fll = {.name = {.ar = "كلية الآداب واللغات", .en = "Faculty of Letters and Languages", .fr = "Faculté des Lettres et des Langues"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umbm_fll_dfll = {.name = {.ar = "قسم اللغة الفرنسية وآدابها", .en = "Department of French Language and Literature", .fr = "Département de Langue et Littérature Françaises"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fll_dall = {.name = {.ar = "قسم اللغة العربية وآدابها", .en = "Department of Arabic Language and Literature", .fr = "Département de Langue et Littérature arabes"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fll_dell = {.name = {.ar = "قسم اللغة الإنجليزية وآدابها", .en = "Department of English Language and Literature", .fr = "Département de Langue et Littérature Anglaises"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fdsp = {.name = {.ar = "كلية الحقوق والعلوم السياسية", .en = "Faculty of Law and Political Sciences", .fr = "Faculté de Droit et Sciences Politiques"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umbm_fdsp_ddroit = {.name = {.ar = "قسم القانون", .en = "Department of Law", .fr = "Département de Droit"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fdsp_dsp = {.name = {.ar = "قسم العلوم السياسية", .en = "Department of Political Science", .fr = "Département de Sciences Politiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_ftech = {.name = {.ar = "كلية التكنولوجيا", .en = "Faculty of Technology", .fr = "Faculté de Technologie"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umbm_ftech_dhydr = {.name = {.ar = "قسم الهيدروليكا", .en = "Department of Hydraulics", .fr = "Département d'Hydraulique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_ftech_dce = {.name = {.ar = "قسم الهندسة المدنية", .en = "Department of Civil Engineering", .fr = "Département de Génie Civil"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_ftech_dme = {.name = {.ar = "قسم الهندسة الميكانيكية", .en = "Department of Mecanical Engineering", .fr = "Département de Génie Mécanique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_ftech_dee = {.name = {.ar = "قسم الهندسة الكهربائية", .en = "Department of Electrical Engineering", .fr = "Département de Génie Electrique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_ftech_delec = {.name = {.ar = "قسم الالكترونيات", .en = "Department of Electronics", .fr = "Département d'Electronique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_iutm = {.name = {.ar = "معهد إدارة التكنولوجيا الحضرية", .en = "Urban Technology Management Institute", .fr = "Institut de Gestion des Technologies Urbaines"}, .type = INSTITUTE, .terms = NULL};
static kuliya_schema umbm_iutm_dcm = {.name = {.ar = "قسم الاستشارات العلمية", .en = "Department of Scientific Counsil", .fr = "Département du Conseil Scientifique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_iutm_due = {.name = {.ar = "قسم الهندسة الحضرية", .en = "Department of Urban Engineering", .fr = "Département de Génie Urbain"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_iutm_dcg = {.name = {.ar = "قسم الأرضية المشتركة", .en = "Departement of common ground", .fr = "Département de terrain d'entente"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsegc = {.name = {.ar = "كلية العلوم الإقتصادية والتجارية وعلوم التسيير", .en = "Faculty of Economics, Business and Management Sciences", .fr = "Faculté des Sciences économiques, Commerciales et de Gestion"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umbm_fsegc_dsfc = {.name = {.ar = "قسم علوم المالية والمحاسبة", .en = "Department of Finance and Accounting Sciences", .fr = "Département des Sciences Financières et Comptables"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsegc_dsg = {.name = {.ar = "قسم علوم التسيير", .en = "Department of Management Sciences", .fr = "Département des Sciences de Gestion"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsegc_dse = {.name = {.ar = "قسم العلوم الإقتصادية", .en = "Department of Economic Sciences", .fr = "Département des Sciences économiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsegc_dsc = {.name = {.ar = "قسم العلوم التجارية", .en = "Department of Commercial Sciences", .fr = "Département des Sciences Commerciales"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fmi = {.name = {.ar = "كلية الرياضيات و اﻹعلام اﻵلي", .en = "Faculty of Mathematics and Computer Science", .fr = "Faculté des mathématiques et de l'informatique"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umbm_fmi_dcs = {.name = {.ar = "قسم اﻹعلام اﻵلي", .en = "Department of Computer Science", .fr = "Département Informatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fmi_dmath = {.name = {.ar = "قسم الرياضيات", .en = "Department of Mathematics", .fr = "Département des Mathématiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fshs = {.name = {.ar = "كلية العلوم الإنسانية والاجتماعية", .en = "Faculty of Human Sciences and Social Sciences", .fr = "Faculté des sciences humaines et sociales"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umbm_fshs_dhist = {.name = {.ar = "قسم التاريخ", .en = "Department of History", .fr = "Département d'Histoire"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fshs_dphilo = {.name = {.ar = "قسم الفلسفة", .en = "Department of Philosophy", .fr = "Département de Philosophie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fshs_dsci = {.name = {.ar = "قسم علوم الاعلام والاتصال", .en = "Department of Information and Communication Sciences", .fr = "Département des Sciences de l'Information et de la Communication"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fshs_dsi = {.name = {.ar = "قسم العلوم الإسلامية", .en = "Department of Islamic Sciences", .fr = "Département des sciences islamiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fshs_dsocio = {.name = {.ar = "قسم علم الاجتماع", .en = "Department of Sociology", .fr = "Département de Sociologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsci = {.name = {.ar = "كلية العلوم", .en = "Faculty of Sciences", .fr = "Faculté des sciences"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umbm_fsci_dchi = {.name = {.ar = "قسم الكيمياء", .en = "Department of Chemistry", .fr = "Département de Chimie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsci_dsa = {.name = {.ar = "قسم علوم الأرغونوميك", .en = "Department of Argonomic Sciences", .fr = "Département des Sciences Argonomiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsci_dbcmb = {.name = {.ar = "قسم الكيمياء الحيوية والأحياء الدقيقة", .en = "Department of Biochemistry and Microbiology", .fr = "Département de Biochimie et de Microbiologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsci_dphy = {.name = {.ar = "قسم الفيزياء", .en = "Department of Physics", .fr = "Département de Physique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_fsci_dsnv = {.name = {.ar = "قسم علوم الطبيعة و الحياة", .en = "Department of Natural and Life Sciences", .fr = "Département des Sciences de la Nature et de la Vie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_istaps = {.name = {.ar = "معهد علوم وتقنيات النشاطات البدنية", .en = "Institute of Sciences and Technologies of Physical Activities", .fr = "Institut des sciences et technologies des activités physiques"}, .type = INSTITUTE, .terms = NULL};
static kuliya_schema umbm_istaps_dags = {.name = {.ar = "قسم الإدارة و التسيير الرياضي", .en = "Department of Sports Administration and Management", .fr = "Département d'administration et de gestion des sports"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_istaps_dcbf = {.name = {.ar = "قسم التكوين القاعدي المشترك", .en = "Department of Common Basal Formation", .fr = "Département de Formation Basale Commune"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_istaps_dapsa = {.name = {.ar = "قسم النشاط البدني و الرياضي المكيف", .en = "Department of Adapted physical and sports activity", .fr = "Département d'Activité Physique et Sportive Adaptée"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_istaps_dfc = {.name = {.ar = "قسم التدريب الرياضي", .en = "Sports Training Department", .fr = "Département de la formation sportive"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_istaps_dep = {.name = {.ar = "قسم التربية البدنية", .en = "Department of Physical Education", .fr = "Département d'éducation Physique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umbm_istaps_dmcs = {.name = {.ar = "قسم الإعلام و الإتصال الرياضي", .en = "Department of Media and Sports Communication", .fr = "Département des Médias et de la Communication Sportive"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umkb = {.name = {.ar = "جامعة محمد خيضر بسكرة", .en = "University of Mohamed Khider Biskra", .fr = "Université Mohamed Khider Biskra"}, .type = UNIVERSITY, .terms = NULL};
static kuliya_schema umkb_fll = {.name = {.ar = "كلية الآداب واللغات", .en = "Faculty of Arts and Languages", .fr = "Faculté des Lettres et des Langues"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umkb_fdsp = {.name = {.ar = "كلية العلوم الاقتصادية والتجارية وعلوم التسيير", .en = "Faculty of Law and Political Science", .fr = "Faculté de Droit et et des Sciences politiques"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umkb_fsecsg = {.name = {.ar = "كلية العلوم الاقتصادية والتجارية وعلوم التسيير", .en = "Faculty of Economic, Commercial and Management Sciences", .fr = "Faculté des Sciences Economiques et Commerciales et des Sciences de Gestion"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umkb_fshs = {.name = {.ar = "كلية العلوم الانسانية و الاجتماعية", .en = "Faculty of Humanities and Social Sciences", .fr = "Faculté des Sciences Humaines et Sociales"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umkb_fsesnv = {.name = {.ar = "كلية العلوم الدقيقة و علوم الطبيعة و الحياة", .en = "Faculty of The Exact Sciences, Natural, and Life Sciences", .fr = "Faculté des Sciences Exactes, des Sciences de la nature et de la Vie"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umkb_fst = {.name = {.ar = "كلية العلوم والتكنلوجيا", .en = "Faculty of Science and Technology", .fr = "Faculté des Sciences et de la Technologie"}, .type = FACULTY, .terms = NULL};
static kuliya_schema umkb_fst_dee = {.name = {.ar = "قسم الهندسة كهربائية", .en = "Department of Electrical Engeniering", .fr = "Departement de Génie Electrique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema umkb_fst_dee_sec = {.name = {.ar = "تخصص التحكم الكهربائي", .en = "Specialy of Electrical Control", .fr = "Spécialité de commande électrique"}, .type = SPECIALTY, .terms = NULL};
static kuliya_schema umkb_istaps = {.name = {.ar = "معهد علوم و تتقنيات النشاطات البدنية و الرياضية", .en = "Institute of Sciences and Techniques of Physical Activities and Sports", .fr = "Institut des Sciences et Techniques des Activités Physiques et Sportives"}, .type = INSTITUTE, .terms = NULL};
static kuliya_schema usto = {.name = {.ar = "جامعة وهران للعلوم و التكنولوجيا محمد بوضياف", .en = "University of Sciences and Technology Oran Mohamed Boudiaf", .fr = "Université Des Sciences et de la Technologie Oran Mohamed Boudiaf"}, .type = UNIVERSITY, .terms = NULL};
static kuliya_schema usto_ieps = {.name = {.ar = "معهد التربية البدنية والرياضة", .en = "Institute Of Physical Education And Sport", .fr = "Institut d'éducation physique et de sport"}, .type = INSTITUTE, .terms = NULL};
static kuliya_schema usto_fch = {.name = {.ar = "كلية الكيمياء", .en = "Faculty of Chemistry", .fr = "Faculté de chimie"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usto_fch_dgc = {.name = {.ar = "قسم الهندسة الكيميائية", .en = "Departement of chemical engineering", .fr = "Déparetement Génie chimique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fch_dchm = {.name = {.ar = "قسم كيمياء المواد", .en = "Departement of Materials chemistry", .fr = "Déparetement Chimie des matériaux"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fch_dchp = {.name = {.ar = "قسم الكيمياء الفيزيائية", .en = "Departement of  Physical chemistry", .fr = "Déparetement Chimie physique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_ista = {.name = {.ar = "معهد العلوم التطبيقية والتكنولوجيا", .en = "Institute of Applied Science and Technology", .fr = "Institut des Sciences et Techniques Appliquées"}, .type = INSTITUTE, .terms = NULL};
static kuliya_schema usto_fmi = {.name = {.ar = "كلية الرياضيات و الاعلام الالي ", .en = "Faculty  Mathematics and Computer Science", .fr = "Faculté des Mathématiques et Informatique"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usto_fmi_dinf = {.name = {.ar = "قسم الرياضيات", .en = "Departement of Mathematics", .fr = "Déparetement mathématiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fmi_dma = {.name = {.ar = "قسم الاعلام الالي", .en = "Departement of  Computer science", .fr = "Déparetement Informatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fsnv = {.name = {.ar = "قسم المعيشة والبيئة", .en = "Departement of Living and environment", .fr = "Déparetement Vivant et environnement"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usto_fsnv_dbio = {.name = {.ar = "قسم التكنولوجيا الحيوية", .en = "Departement of Biotechnology", .fr = "Déparetement Biotechnologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fsnv_dve = {.name = {.ar = "قسم الهندسة الفيزيائية", .en = "Departement of physics Engineering ", .fr = "Déparetement Génie Phisique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fsnv_dgma = {.name = {.ar = "قسم علم الوراثة الجزيئية التطبيقية", .en = "Departement Applied Molecular Genetics", .fr = "Déparetement Génétique moléculaire appliquée"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fag = {.name = {.ar = "قسم هندسة المياه", .en = "Water engineering department", .fr = "Déparement Génie de l'eau"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fag_da = {.name = {.ar = "قسم العمارة", .en = "Architecture department", .fr = "déparetement Architecture"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fag_dge = {.name = {.ar = "كلية العمارة والهندسة المدنية", .en = "Faculty of Architecture and Civil Engineering", .fr = "Faculté d'architecture et génie civil"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usto_fag_dgc = {.name = {.ar = "قسم الهندسة المدنية", .en = "Civil engineering department", .fr = "Déparement Génie civil"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fge = {.name = {.ar = "كلية الهندسة الكهربائية", .en = "Faculty of Electrical Engineering", .fr = "Faculté de génie électrique"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usto_fge_dau = {.name = {.ar = "قسم الإلكترونيات", .en = "Department Automatic", .fr = "Department Automatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fge_del = {.name = {.ar = "قسم الهندسة الكهربائية", .en = "Departement of Electrical engineering", .fr = "Déparetement Électrotechnique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fge_delt = {.name = {.ar = "قسم الهندسة الكهربائية", .en = "Departement of Electrical engineering ", .fr = "Déparetement Électrotechnique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fgm = {.name = {.ar = "كلية الهندسة الميكانيكية", .en = "Faculty of Mechanical Engineering", .fr = "Faculté de génie mécanique"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usto_fgm_dgme = {.name = {.ar = "قسم الهندسة الميكانيكية", .en = "Department of Mechanical Engineering ", .fr = "Department Génie Mécanique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fgm_dmm = {.name = {.ar = "قسم التعدين والمعادن", .en = "Departement of Mining and Metallurgy", .fr = "Déparetement Mine et Métallurgie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fgm_dgma = {.name = {.ar = "قسم الهندسة البحرية", .en = "Department of Marine Engineering", .fr = "Department Génie Maritime"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fph = {.name = {.ar = "قسم تكنولوجيا المواد", .en = "Faculty of Materials technology ", .fr = "Faculté Technologie des matériaux "}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fph_dgp = {.name = {.ar = "قسم الهندسة الفيزيائية", .en = "Departement of physics Engineering ", .fr = "Déparetement Génie Phisique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fph_dtm = {.name = {.ar = "قسم الاعلام الالي", .en = "Departement of  Computer science", .fr = "Déparetement Informatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usto_fph_dpe = {.name = {.ar = "قسم فيزياء الطاقة", .en = "Departement of Physics energetics", .fr = "deparetement Physique énergétique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ummto = {.name = {.ar = "جامعة مولود معمري", .en = "University of Mouloud Mammeri", .fr = "Université Mouloud Mammeri"}, .type = UNIVERSITY, .terms = NULL};
static kuliya_schema ummto_fmed = {.name = {.ar = "كلية الطب", .en = "Faculty of Medicine", .fr = "Faculté de Médecine"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ummto_fdsp = {.name = {.ar = "كلية الحقوق والعلوم السياسية", .en = "Faculty of Law and Political Sciences", .fr = "Faculté de Droit et des Sciences Politiques"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ummto_fsecsg = {.name = {.ar = "كلية الاقتصاد والأعمال وعلوم التسيير", .en = "Faculty of Economics, Business and Management Sciences", .fr = "Faculté des Sciences Economiques, Commerciales et des Sciences de Gestion"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ummto_fsbsa = {.name = {.ar = "كلية العلوم البيولوجية والعلوم الزراعية", .en = "Faculty of Biological Sciences and Agronomic Sciences", .fr = "Faculté des Sciences Biologiques et des Sciences Agronomiques"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ummto_fshs = {.name = {.ar = "كلية العلوم الإنسانية والاجتماعية", .en = "Faculty of Humanities and Social Sciences", .fr = "Faculté des sciences humaines et sociales"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ummto_dsat = {.name = {.ar = "قسم العلوم التطبيقية والتقنيات", .en = "Department of Applied Sciences and Technologies", .fr = "Département des Sciences Appliquée et des Technologies"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ummto_fgei = {.name = {.ar = "كلية الهندسة الكهربائية وهندسة الإعلام الآلي", .en = "Faculty of Electrical and Computer Engineering", .fr = "Faculté de Génie Electrique et Informatique"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ummto_dmi = {.name = {.ar = "قسم الإعلام الآلي والرياضيات", .en = "Mathematics - Computer Science Department", .fr = "Département Mathématiques - Informatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ummto_fgc = {.name = {.ar = "كلية هندسة التشييد", .en = "Faculty of Construction Engineering", .fr = "Faculté du Génie de la Construction"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb = {.name = {.ar = "جامعة هواري بومدين للعلوم والتكنولوجيا", .en = "University of Sciences and Technology Houari Boumediene", .fr = "Université Des Sciences et de la Technologie Houari Boumediene"}, .type = UNIVERSITY, .terms = NULL};
static kuliya_schema usthb_fgmgp = {.name = {.ar = "كلية الهندسة الميكانيكية وهندسة الطرائق", .en = "Faculty of Mechanical Engineering and Process Engineering", .fr = "Faculté de Génie Mécanique et Génie de Procédés"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb_fgmgp_dcmp = {.name = {.ar = "قسم الإنشاءات الميكانيكية والتصنيع", .en = "Mechanical Construction and Manufacturing Department", .fr = "Département Construction Mécanique and Productique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fgmgp_dgcc = {.name = {.ar = "قسم الهندسة الكيميائية وعلم التبريد", .en = "Department of Chemical Engineering and Cryogenics", .fr = "Département Génie Chimique & Cryogénie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fgmgp_dte = {.name = {.ar = "قسم الطاقة الحرارية", .en = "Thermo Energy Department", .fr = "Département Thermo Énergétique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fgmgp_dgegp = {.name = {.ar = "قسم الهندسة البيئية والهندسة الصيدلانية", .en = "Environmental Engineering and Pharmaceutical Engineering Department", .fr = "Département Génie Environnement & Génie Pharmaceutique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fgmgp_dsm = {.name = {.ar = "قسم علوم المواد", .en = "Department of Materials Sciences", .fr = "Département Sciences des Matériaux"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fsb = {.name = {.ar = "كلية العلوم البيولوجية", .en = "Faculty of Biological Sciences", .fr = "Faculté des Sciences Biologiques"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb_fsb_dee = {.name = {.ar = "قسم البيئة", .en = "Department of Ecology and Environment", .fr = "Département Écologie et Environnement"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fsb_dbcm = {.name = {.ar = "قسم البيولوجيا الخلوية والجزيئية", .en = "Cellular and Molecular Biology Department", .fr = "Département Biologie Cellulaire et Moléculaire"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fsb_dbpo = {.name = {.ar = "قسم علم الأحياء ووظائف الأعضاء", .en = "Department of Biology and Physiology of Organisms", .fr = "Département Biologie et Physiologie des Organismes"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fchimie = {.name = {.ar = "كلية الكيمياء", .en = "Faculty of Chemsitry", .fr = "Faculté de Chimie"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb_fchimie_dcpmi = {.name = {.ar = "قسم كيمياء وفيزياء المواد غير العضوية", .en = "Department of Chemistry and Physics of Inorganic Materials", .fr = "Département de Chimie et Physique des Matériaux Inorganique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fchimie_dcm = {.name = {.ar = "قسم الكيمياء الجزيئية", .en = "Department of Macromolecular Chemistry", .fr = "Département de Chimie Macromoleculaire"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fchimie_dcpt = {.name = {.ar = "قسم الكيمياء الفيزيائية والنظرية", .en = "Department of Physical and Theoretical Chemistry", .fr = "Département de Chimie Physique et Théorique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fchimie_dcoa = {.name = {.ar = "قسم الكيمياء العضوية التطبيقية", .en = "Department of Applied Organic Chemistry", .fr = "Département de Chimie Organique Appliquée"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fphy = {.name = {.ar = "كلية الفيزياء", .en = "Faculty of Physics", .fr = "Faculté de Physique"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb_fphy_demf = {.name = {.ar = "قسم ميكانيكا الطاقة والموائع", .en = "Department of Energy and Fluid Mechanics", .fr = "Département d’Energétique et Mécanique des Fluides"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fphy_dmc = {.name = {.ar = "قسم المواد والمكونات", .en = "Materials and Components Department", .fr = "Département Matériaux et Composant"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fphy_dpr = {.name = {.ar = "قسم الفيزياء الإشعاعية", .en = "Department of Radiation Physics", .fr = "Département de Physique des Rayonnements"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fphy_dpt = {.name = {.ar = "قسم الفيزياء النظرية", .en = "Department of Theoretical Physics", .fr = "Département de Physique Théorique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fstgat = {.name = {.ar = "كلية علوم اﻷرض و تهيئة اﻹقليم", .en = "Faculty of Earth Sciences and Country Planning", .fr = "Faculté des Sciences de la terre et Aménagement du Territoire"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb_fstgat_dgat = {.name = {.ar = "قسم الجيوفيزياء", .en = "Department of Geophysics", .fr = "Département de Géophysique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fstgat_dg = {.name = {.ar = "قسم الجيولوجيا", .en = "Department of Geology", .fr = "Département de Géologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fstgat_dgp = {.name = {.ar = "قسم الجغرافيا والتخطيط الإقليمي", .en = "Department of Geography and Regional Planning", .fr = "Département de Géographie et de l’Aménagement du Territoire"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fei = {.name = {.ar = "كلية اﻹلكترونيك و اﻹعلام اﻵلي", .en = "Faculty of Electronics and Computer Science", .fr = "Faculté d’Electronique et d’Informatique"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb_fei_auto = {.name = {.ar = "قسم الأجهزة والأتمتة", .en = "Instrumentation and Automation Department", .fr = "Département Instrumentation et Automatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fei_info = {.name = {.ar = "قسم اﻹعلام اﻵلي", .en = "Department of Computer Science", .fr = "Département Informatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fei_telecom = {.name = {.ar = "قسم اﻹتصال", .en = "Telecommunications Department", .fr = "Département Télécommunication"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fei_elt = {.name = {.ar = "قسم اﻹلكترونيك", .en = "Department of Electronics", .fr = "Département Electrotechnique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fmath = {.name = {.ar = "كلية الرياضيات", .en = "Faculty of Mathematics", .fr = "Faculté de Mathématiques"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb_fmath_da = {.name = {.ar = "قسم التحليل", .en = "Analysis Department", .fr = "Département Analyse"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fmath_dps = {.name = {.ar = "قسم الاحتمالات والإحصاء", .en = "Probability and Statistics Department", .fr = "Département Probabilités et statistiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fmath_dro = {.name = {.ar = "قسم البحوث التشغيلية", .en = "Operational Research Department", .fr = "Département Recherche Opérationnelle"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fmath_datn = {.name = {.ar = "قسم الجبر ونظرية الأعداد", .en = "Department of Algebra and Number Theory", .fr = "Département Algèbre et théorie des nombres"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fgc = {.name = {.ar = "كلية الهندسة المدنية", .en = "Faculty of Civil Engineering", .fr = "Faculté de Génie Civil"}, .type = FACULTY, .terms = NULL};
static kuliya_schema usthb_fgc_dgh = {.name = {.ar = "قسم الجيوتكنيك والهيدروليكا", .en = "Department of Geotechnics and Hydraulics", .fr = "Département de Géotechnique et Hydraulique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema usthb_fgc_dsm = {.name = {.ar = "قسم الهياكل والمواد", .en = "Department of Structures and Materials", .fr = "Département de Structures et Matérieux"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facdr = {.name = {.ar = "كلية الحقوق", .en = "Faculty Of Law", .fr = "Faculté De Droit"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ubma_facdr_pld = {.name = {.ar = "قسم القانون العام", .en = "Public Law Department", .fr = "Département De Droit Public"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facdr_psd = {.name = {.ar = "قسم العلوم السياسية", .en = "Political Sciences Department", .fr = "Département Des Sciences Politiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsc = {.name = {.ar = "كلية العلوم", .en = "Faculty Of Sciences", .fr = "Faculté Des Sciences"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ubma_facsc_pd = {.name = {.ar = "قسم الفلسفة", .en = "Physics Department", .fr = "Département De Philosophie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsc_ssd = {.name = {.ar = "قسم علوم البحار", .en = "Sea Sciences Department", .fr = "Département Des Sciences De La Mer"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsc_nlsd = {.name = {.ar = "قسم علوم الطبيعة والحياة", .en = "Nature And Life Sciences Department", .fr = "Département Nature Et Sciences De La Vie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsc_bd = {.name = {.ar = "قسم علم المكتبيات", .en = "Biology Department", .fr = "Département Biblitheconomy"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsc_mcd = {.name = {.ar = "قسم الرياضيات و الإعلام الألي", .en = "Mathematics And Computing Department", .fr = "Département Mathématiques Et Informatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsc_md = {.name = {.ar = "قسم الرياضيات", .en = "Mathematics Department", .fr = "Département De Mathématiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsc_msd = {.name = {.ar = "قسم العلوم الإدارية", .en = "Material Sciences Department", .fr = "Département Des Sciences De Gestion"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsc_cd = {.name = {.ar = "قسم الكيمياء", .en = "Chemistry Department", .fr = "Département De Chimie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facscm = {.name = {.ar = "كلية العلوم الطبية", .en = "Faculty Of Medical Sciences", .fr = "Faculté Des Sciences Médicales"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ubma_facscm_pd = {.name = {.ar = "قسم الصيدلة", .en = "Pharmacy Department", .fr = "Département de Pharmacie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facscm_ddm = {.name = {.ar = "قسم طب الأسنان", .en = "Department Of Dental Medicine", .fr = "Département De Médecine Dentaire"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facscm_md = {.name = {.ar = "قسم الطب", .en = "Medicine Department", .fr = "Département De Mathématiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facscm_tt = {.name = {.ar = "", .en = "Teacher Training", .fr = ""}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs = {.name = {.ar = "كلية الآداب والعلوم الإنسانية والاجتماعية", .en = "Faculty Of Letters, Humanities And Social Sciences", .fr = "Faculté Des Lettres, Sciences Humaines Et Sociales"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ubma_faclschs_pd = {.name = {.ar = "قسم الفلسفة", .en = "Philosophy Department", .fr = "Département De Philosophie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_alld = {.name = {.ar = "قسم اللغة العربية وآدابها", .en = "Arabic Language And Literature Department", .fr = "Département De Langue Et Littérature Arabes"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_sd = {.name = {.ar = "قسم الاجتماع", .en = "Sociology Department", .fr = "Département De Sociologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_icsd = {.name = {.ar = "قسم علوم الإعلام والاتصال", .en = "Information And Communication Sciences Department", .fr = "Département Des Sciences De L'Information Et De La Communication"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_fld = {.name = {.ar = "قسم اللغة الفرنسية", .en = "French Language Department", .fr = "Département De Langue Française"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_hd = {.name = {.ar = "قسم التاريخ", .en = "History Department", .fr = "Département D'Histoire"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_bd = {.name = {.ar = "قسم علم المكتبيات", .en = "Biblitheconomy Department", .fr = "Département Biblitheconomy"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_eld = {.name = {.ar = "قسم اللغة الإنجليزية", .en = "English Language Department", .fr = "Département De Langue Anglaise"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_td = {.name = {.ar = "قسم الترجمة", .en = "Translation Department", .fr = "Service De Traduction"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_hssd = {.name = {.ar = "قسم العلوم الإنسانية والاجتماعية", .en = "Human And Social Sciences Department", .fr = "Département Des Sciences Humaines Et Sociales"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_psed = {.name = {.ar = "قسم التربية البدنية والرياضية", .en = "Physical And Sports Education Department", .fr = "Service D'Éducation Physique Et Sportive"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_faclschs_ild = {.name = {.ar = "قسم اللغة الإيطالية", .en = "Italian Language Department", .fr = "Département De Langue Italienne"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsceg = {.name = {.ar = "كلية الاقتصاد وعلوم التسيير", .en = "Faculty Of Economics And Management Sciences", .fr = "Faculté Des Sciences Économiques Et De Gestion"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ubma_facsceg_esd = {.name = {.ar = "قسم العلوم الاقتصادية", .en = "Economic Sciences Department", .fr = "Département Des Sciences Économiques"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsceg_ct = {.name = {.ar = "جذع مشترك", .en = "Common Trunk", .fr = "Tronc Commun"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsceg_fsd = {.name = {.ar = "قسم العلوم المالية", .en = "Financial Sciences Department", .fr = "Département Des Sciences Financières"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsceg_msd = {.name = {.ar = "قسم العلوم الإدارية", .en = "Management Sciences Department", .fr = "Département Des Sciences De Gestion"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsct = {.name = {.ar = "كلية علوم الأرض", .en = "Faculty Of Earth Sciences", .fr = "Faculté Des Sciences De La Terre"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ubma_facsct_pd = {.name = {.ar = "قسم التخطيط", .en = "Planning Department", .fr = "Département de la Planification"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsct_ad = {.name = {.ar = "قسم العمارة", .en = "Architecture Department", .fr = "Département D'Architecture"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsct_md = {.name = {.ar = "قسم التعدين", .en = "Mining Department", .fr = "Département des Mines"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsct_gd = {.name = {.ar = "قسم الجيولوجيا", .en = "Geology Department", .fr = "Département De Géologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci = {.name = {.ar = "كلية العلوم الهندسية", .en = "Faculty Of Engineering Sciences", .fr = "Faculté Des Sciences De L'Ingénieur"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ubma_facsci_ped = {.name = {.ar = "قسم هندسة العمليات", .en = "Process Engineering Department", .fr = "Département Génie Des Procédés"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_hd = {.name = {.ar = "قسم الهيدروليك", .en = "Hydraulic Department", .fr = "Département Hydraulique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_ed = {.name = {.ar = "القسم الكهروتقني", .en = "Electrotechnical Department", .fr = "Département Électrotechnique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_std = {.name = {.ar = "قسم العلوم والتكنولوجيا", .en = "Science And Technology Department", .fr = "Département Des Sciences Et De La Technologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_csd = {.name = {.ar = "قسم الإعلام الألي", .en = "Computer Science Department", .fr = "Département Informatique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_md = {.name = {.ar = "قسم علم المعادن", .en = "Metalurgy Department", .fr = "Département Métallurgie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_tt = {.name = {.ar = "", .en = "Teacher Training", .fr = ""}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_ced = {.name = {.ar = "قسم الهندسة المدنية", .en = "Civil Engineering Department", .fr = "Département Génie Civil"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_d = {.name = {.ar = "", .en = "Doctorat", .fr = ""}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ubma_facsci_med = {.name = {.ar = "قسم الهندسة الميكانيكية", .en = "Mechanical Engineering Department", .fr = "Département de Génie Mécanique"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks = {.name = {.ar = "جامعة الجزائر 2  أبو القاسم سعد الله", .en = "University of Algiers 2 Abou El-kacem Saâdallah", .fr = "Université d’Alger 2 Abou El Kacem Saâdallah"}, .type = UNIVERSITY, .terms = NULL};
static kuliya_schema ua2aks_fle = {.name = {.ar = "كلية العلوم الإنسانية", .en = "Faculty of Humanities", .fr = "Faculté des Sciences Humaines"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ua2aks_fle_dfr = {.name = {.ar = "قسم اللغة الفرنسية ", .en = "Department of French", .fr = "Département de Langue Française"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_fle_dsgi = {.name = {.ar = "قسم اللغات الاسبانية , الألمانية , الايطالية  ", .en = "Department of Spanish, German & Italian", .fr = "Département des Langues Espagnole, Allemande, et Italienne"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_fle_den = {.name = {.ar = "قسم اللغة الانجليزية ", .en = "Department of English", .fr = "Département de Langue Anglaise"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_it = {.name = {.ar = "معهد الآثار", .en = "Institute of archology", .fr = "Institut d’archéologie"}, .type = INSTITUTE, .terms = NULL};
static kuliya_schema ua2aks_ia = {.name = {.ar = "معهد الترجمة", .en = "Institute of translation", .fr = "Institut de traduction"}, .type = INSTITUTE, .terms = NULL};
static kuliya_schema ua2aks_fss = {.name = {.ar = "كلية العلوم الإنسانية", .en = "Faculty of humanities", .fr = "Faculté des sciences humaines"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ua2aks_fss_dedu = {.name = {.ar = "قسم علوم التربية", .en = "Department of educational sciences", .fr = "Département de sciences de l’éducation"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_fss_dpsy = {.name = {.ar = "قسم علم النفس", .en = "Department of psychology", .fr = "Département de psychologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_fss_dst = {.name = {.ar = "قسم الأرطوفونيا", .en = "Department of speech therapy", .fr = "Département d'orthophonie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_fss_dsocio = {.name = {.ar = "قسم علم الاجتماع", .en = "Department of sociology", .fr = "Département de sociologie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_fsh = {.name = {.ar = "كلية العلوم الإنسانية", .en = "Faculty of Humanities", .fr = "Faculté des Sciences Humaines"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ua2aks_fsh_dh = {.name = {.ar = "قسم الفلسفة", .en = "Department of philosophy", .fr = "Département de philosophie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_fsh_dph = {.name = {.ar = "قسم التاريخ", .en = "Department of history", .fr = "Département d'اhistoire"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_fsh_dld = {.name = {.ar = "قسم علم المكتبات والتوثيق", .en = "Department of librarianship and documentation", .fr = "Département de bibliothéconomie"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_falaol = {.name = {.ar = "كلية العلوم الإنسانية", .en = "Faculty of Humanities", .fr = "Faculté des Sciences Humaines"}, .type = FACULTY, .terms = NULL};
static kuliya_schema ua2aks_falaol_dts = {.name = {.ar = "قسم علوم اللسان ", .en = "Department of Tongue Sciences", .fr = "Département des Sciences du Langage"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_falaol_dart = {.name = {.ar = "قسم الفنون ", .en = "Department of Arts", .fr = "Département des Arts"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_falaol_dtrl = {.name = {.ar = "قسم اللغة التركية والروسية ", .en = "Department of Turkish and Russian Languages", .fr = "Département de langues Turque et Russe"}, .type = DEPARTMENT, .terms = NULL};
static kuliya_schema ua2aks_falaol_dala = {.name = {.ar = "قسم اللغة العربية وآدابها ", .en = "Department of Arabic Language and Arts", .fr = "Département de Langue et Lettres arabes et Langues Orientales"}, .type = DEPARTMENT, .terms = NULL};

static void __kuliya_init()
{
	umkb_fst_dee_sec.terms = (kuliya_terms *)malloc(sizeof(kuliya_terms));
	umkb_fst_dee_sec.terms->per_year = 2;
	umkb_fst_dee_sec.terms->number_of_slots = 4;
	umkb_fst_dee_sec.terms->slots = (int *)malloc(4 * sizeof(int));
	umkb_fst_dee_sec.terms->slots[0] = 7;
	umkb_fst_dee_sec.terms->slots[1] = 8;
	umkb_fst_dee_sec.terms->slots[2] = 9;
	umkb_fst_dee_sec.terms->slots[3] = 10;
}

static void __kuliya_deinit()
{
	free(umkb_fst_dee_sec.terms->slots);
	free(umkb_fst_dee_sec.terms);
}

static kuliya_schema *__get_node_by_path(const char *path)
{
	if (STR_EQ("umbm", path))
		return &umbm;

	if (STR_EQ("umbm/fll", path))
		return &umbm_fll;

	if (STR_EQ("umbm/fll/dfll", path))
		return &umbm_fll_dfll;

	if (STR_EQ("umbm/fll/dall", path))
		return &umbm_fll_dall;

	if (STR_EQ("umbm/fll/dell", path))
		return &umbm_fll_dell;

	if (STR_EQ("umbm/fdsp", path))
		return &umbm_fdsp;

	if (STR_EQ("umbm/fdsp/ddroit", path))
		return &umbm_fdsp_ddroit;

	if (STR_EQ("umbm/fdsp/dsp", path))
		return &umbm_fdsp_dsp;

	if (STR_EQ("umbm/ftech", path))
		return &umbm_ftech;

	if (STR_EQ("umbm/ftech/dhydr", path))
		return &umbm_ftech_dhydr;

	if (STR_EQ("umbm/ftech/dce", path))
		return &umbm_ftech_dce;

	if (STR_EQ("umbm/ftech/dme", path))
		return &umbm_ftech_dme;

	if (STR_EQ("umbm/ftech/dee", path))
		return &umbm_ftech_dee;

	if (STR_EQ("umbm/ftech/delec", path))
		return &umbm_ftech_delec;

	if (STR_EQ("umbm/iutm", path))
		return &umbm_iutm;

	if (STR_EQ("umbm/iutm/dcm", path))
		return &umbm_iutm_dcm;

	if (STR_EQ("umbm/iutm/due", path))
		return &umbm_iutm_due;

	if (STR_EQ("umbm/iutm/dcg", path))
		return &umbm_iutm_dcg;

	if (STR_EQ("umbm/fsegc", path))
		return &umbm_fsegc;

	if (STR_EQ("umbm/fsegc/dsfc", path))
		return &umbm_fsegc_dsfc;

	if (STR_EQ("umbm/fsegc/dsg", path))
		return &umbm_fsegc_dsg;

	if (STR_EQ("umbm/fsegc/dse", path))
		return &umbm_fsegc_dse;

	if (STR_EQ("umbm/fsegc/dsc", path))
		return &umbm_fsegc_dsc;

	if (STR_EQ("umbm/fmi", path))
		return &umbm_fmi;

	if (STR_EQ("umbm/fmi/dcs", path))
		return &umbm_fmi_dcs;

	if (STR_EQ("umbm/fmi/dmath", path))
		return &umbm_fmi_dmath;

	if (STR_EQ("umbm/fshs", path))
		return &umbm_fshs;

	if (STR_EQ("umbm/fshs/dhist", path))
		return &umbm_fshs_dhist;

	if (STR_EQ("umbm/fshs/dphilo", path))
		return &umbm_fshs_dphilo;

	if (STR_EQ("umbm/fshs/dsci", path))
		return &umbm_fshs_dsci;

	if (STR_EQ("umbm/fshs/dsi", path))
		return &umbm_fshs_dsi;

	if (STR_EQ("umbm/fshs/dsocio", path))
		return &umbm_fshs_dsocio;

	if (STR_EQ("umbm/fsci", path))
		return &umbm_fsci;

	if (STR_EQ("umbm/fsci/dchi", path))
		return &umbm_fsci_dchi;

	if (STR_EQ("umbm/fsci/dsa", path))
		return &umbm_fsci_dsa;

	if (STR_EQ("umbm/fsci/dbcmb", path))
		return &umbm_fsci_dbcmb;

	if (STR_EQ("umbm/fsci/dphy", path))
		return &umbm_fsci_dphy;

	if (STR_EQ("umbm/fsci/dsnv", path))
		return &umbm_fsci_dsnv;

	if (STR_EQ("umbm/istaps", path))
		return &umbm_istaps;

	if (STR_EQ("umbm/istaps/dags", path))
		return &umbm_istaps_dags;

	if (STR_EQ("umbm/istaps/dcbf", path))
		return &umbm_istaps_dcbf;

	if (STR_EQ("umbm/istaps/dapsa", path))
		return &umbm_istaps_dapsa;

	if (STR_EQ("umbm/istaps/dfc", path))
		return &umbm_istaps_dfc;

	if (STR_EQ("umbm/istaps/dep", path))
		return &umbm_istaps_dep;

	if (STR_EQ("umbm/istaps/dmcs", path))
		return &umbm_istaps_dmcs;

	if (STR_EQ("umkb", path))
		return &umkb;

	if (STR_EQ("umkb/fll", path))
		return &umkb_fll;

	if (STR_EQ("umkb/fdsp", path))
		return &umkb_fdsp;

	if (STR_EQ("umkb/fsecsg", path))
		return &umkb_fsecsg;

	if (STR_EQ("umkb/fshs", path))
		return &umkb_fshs;

	if (STR_EQ("umkb/fsesnv", path))
		return &umkb_fsesnv;

	if (STR_EQ("umkb/fst", path))
		return &umkb_fst;

	if (STR_EQ("umkb/fst/dee", path))
		return &umkb_fst_dee;

	if (STR_EQ("umkb/fst/dee/sec", path))
		return &umkb_fst_dee_sec;

	if (STR_EQ("umkb/istaps", path))
		return &umkb_istaps;

	if (STR_EQ("usto", path))
		return &usto;

	if (STR_EQ("usto/ieps", path))
		return &usto_ieps;

	if (STR_EQ("usto/fch", path))
		return &usto_fch;

	if (STR_EQ("usto/fch/dgc", path))
		return &usto_fch_dgc;

	if (STR_EQ("usto/fch/dchm", path))
		return &usto_fch_dchm;

	if (STR_EQ("usto/fch/dchp", path))
		return &usto_fch_dchp;

	if (STR_EQ("usto/ista", path))
		return &usto_ista;

	if (STR_EQ("usto/fmi", path))
		return &usto_fmi;

	if (STR_EQ("usto/fmi/dinf", path))
		return &usto_fmi_dinf;

	if (STR_EQ("usto/fmi/dma", path))
		return &usto_fmi_dma;

	if (STR_EQ("usto/fsnv", path))
		return &usto_fsnv;

	if (STR_EQ("usto/fsnv/dbio", path))
		return &usto_fsnv_dbio;

	if (STR_EQ("usto/fsnv/dve", path))
		return &usto_fsnv_dve;

	if (STR_EQ("usto/fsnv/dgma", path))
		return &usto_fsnv_dgma;

	if (STR_EQ("usto/fag", path))
		return &usto_fag;

	if (STR_EQ("usto/fag/da", path))
		return &usto_fag_da;

	if (STR_EQ("usto/fag/dge", path))
		return &usto_fag_dge;

	if (STR_EQ("usto/fag/dgc", path))
		return &usto_fag_dgc;

	if (STR_EQ("usto/fge", path))
		return &usto_fge;

	if (STR_EQ("usto/fge/dau", path))
		return &usto_fge_dau;

	if (STR_EQ("usto/fge/del", path))
		return &usto_fge_del;

	if (STR_EQ("usto/fge/delt", path))
		return &usto_fge_delt;

	if (STR_EQ("usto/fgm", path))
		return &usto_fgm;

	if (STR_EQ("usto/fgm/dgme", path))
		return &usto_fgm_dgme;

	if (STR_EQ("usto/fgm/dmm", path))
		return &usto_fgm_dmm;

	if (STR_EQ("usto/fgm/dgma", path))
		return &usto_fgm_dgma;

	if (STR_EQ("usto/fph", path))
		return &usto_fph;

	if (STR_EQ("usto/fph/dgp", path))
		return &usto_fph_dgp;

	if (STR_EQ("usto/fph/dtm", path))
		return &usto_fph_dtm;

	if (STR_EQ("usto/fph/dpe", path))
		return &usto_fph_dpe;

	if (STR_EQ("ummto", path))
		return &ummto;

	if (STR_EQ("ummto/fmed", path))
		return &ummto_fmed;

	if (STR_EQ("ummto/fdsp", path))
		return &ummto_fdsp;

	if (STR_EQ("ummto/fsecsg", path))
		return &ummto_fsecsg;

	if (STR_EQ("ummto/fsbsa", path))
		return &ummto_fsbsa;

	if (STR_EQ("ummto/fshs", path))
		return &ummto_fshs;

	if (STR_EQ("ummto/dsat", path))
		return &ummto_dsat;

	if (STR_EQ("ummto/fgei", path))
		return &ummto_fgei;

	if (STR_EQ("ummto/dmi", path))
		return &ummto_dmi;

	if (STR_EQ("ummto/fgc", path))
		return &ummto_fgc;

	if (STR_EQ("usthb", path))
		return &usthb;

	if (STR_EQ("usthb/fgmgp", path))
		return &usthb_fgmgp;

	if (STR_EQ("usthb/fgmgp/dcmp", path))
		return &usthb_fgmgp_dcmp;

	if (STR_EQ("usthb/fgmgp/dgcc", path))
		return &usthb_fgmgp_dgcc;

	if (STR_EQ("usthb/fgmgp/dte", path))
		return &usthb_fgmgp_dte;

	if (STR_EQ("usthb/fgmgp/dgegp", path))
		return &usthb_fgmgp_dgegp;

	if (STR_EQ("usthb/fgmgp/dsm", path))
		return &usthb_fgmgp_dsm;

	if (STR_EQ("usthb/fsb", path))
		return &usthb_fsb;

	if (STR_EQ("usthb/fsb/dee", path))
		return &usthb_fsb_dee;

	if (STR_EQ("usthb/fsb/dbcm", path))
		return &usthb_fsb_dbcm;

	if (STR_EQ("usthb/fsb/dbpo", path))
		return &usthb_fsb_dbpo;

	if (STR_EQ("usthb/fchimie", path))
		return &usthb_fchimie;

	if (STR_EQ("usthb/fchimie/dcpmi", path))
		return &usthb_fchimie_dcpmi;

	if (STR_EQ("usthb/fchimie/dcm", path))
		return &usthb_fchimie_dcm;

	if (STR_EQ("usthb/fchimie/dcpt", path))
		return &usthb_fchimie_dcpt;

	if (STR_EQ("usthb/fchimie/dcoa", path))
		return &usthb_fchimie_dcoa;

	if (STR_EQ("usthb/fphy", path))
		return &usthb_fphy;

	if (STR_EQ("usthb/fphy/demf", path))
		return &usthb_fphy_demf;

	if (STR_EQ("usthb/fphy/dmc", path))
		return &usthb_fphy_dmc;

	if (STR_EQ("usthb/fphy/dpr", path))
		return &usthb_fphy_dpr;

	if (STR_EQ("usthb/fphy/dpt", path))
		return &usthb_fphy_dpt;

	if (STR_EQ("usthb/fstgat", path))
		return &usthb_fstgat;

	if (STR_EQ("usthb/fstgat/dgat", path))
		return &usthb_fstgat_dgat;

	if (STR_EQ("usthb/fstgat/dg", path))
		return &usthb_fstgat_dg;

	if (STR_EQ("usthb/fstgat/dgp", path))
		return &usthb_fstgat_dgp;

	if (STR_EQ("usthb/fei", path))
		return &usthb_fei;

	if (STR_EQ("usthb/fei/auto", path))
		return &usthb_fei_auto;

	if (STR_EQ("usthb/fei/info", path))
		return &usthb_fei_info;

	if (STR_EQ("usthb/fei/telecom", path))
		return &usthb_fei_telecom;

	if (STR_EQ("usthb/fei/elt", path))
		return &usthb_fei_elt;

	if (STR_EQ("usthb/fmath", path))
		return &usthb_fmath;

	if (STR_EQ("usthb/fmath/da", path))
		return &usthb_fmath_da;

	if (STR_EQ("usthb/fmath/dps", path))
		return &usthb_fmath_dps;

	if (STR_EQ("usthb/fmath/dro", path))
		return &usthb_fmath_dro;

	if (STR_EQ("usthb/fmath/datn", path))
		return &usthb_fmath_datn;

	if (STR_EQ("usthb/fgc", path))
		return &usthb_fgc;

	if (STR_EQ("usthb/fgc/dgh", path))
		return &usthb_fgc_dgh;

	if (STR_EQ("usthb/fgc/dsm", path))
		return &usthb_fgc_dsm;

	if (STR_EQ("ubma/facdr", path))
		return &ubma_facdr;

	if (STR_EQ("ubma/facdr/pld", path))
		return &ubma_facdr_pld;

	if (STR_EQ("ubma/facdr/psd", path))
		return &ubma_facdr_psd;

	if (STR_EQ("ubma/facsc", path))
		return &ubma_facsc;

	if (STR_EQ("ubma/facsc/pd", path))
		return &ubma_facsc_pd;

	if (STR_EQ("ubma/facsc/ssd", path))
		return &ubma_facsc_ssd;

	if (STR_EQ("ubma/facsc/nlsd", path))
		return &ubma_facsc_nlsd;

	if (STR_EQ("ubma/facsc/bd", path))
		return &ubma_facsc_bd;

	if (STR_EQ("ubma/facsc/mcd", path))
		return &ubma_facsc_mcd;

	if (STR_EQ("ubma/facsc/md", path))
		return &ubma_facsc_md;

	if (STR_EQ("ubma/facsc/msd", path))
		return &ubma_facsc_msd;

	if (STR_EQ("ubma/facsc/cd", path))
		return &ubma_facsc_cd;

	if (STR_EQ("ubma/facscm", path))
		return &ubma_facscm;

	if (STR_EQ("ubma/facscm/pd", path))
		return &ubma_facscm_pd;

	if (STR_EQ("ubma/facscm/ddm", path))
		return &ubma_facscm_ddm;

	if (STR_EQ("ubma/facscm/md", path))
		return &ubma_facscm_md;

	if (STR_EQ("ubma/facscm/tt", path))
		return &ubma_facscm_tt;

	if (STR_EQ("ubma/faclschs", path))
		return &ubma_faclschs;

	if (STR_EQ("ubma/faclschs/pd", path))
		return &ubma_faclschs_pd;

	if (STR_EQ("ubma/faclschs/alld", path))
		return &ubma_faclschs_alld;

	if (STR_EQ("ubma/faclschs/sd", path))
		return &ubma_faclschs_sd;

	if (STR_EQ("ubma/faclschs/icsd", path))
		return &ubma_faclschs_icsd;

	if (STR_EQ("ubma/faclschs/fld", path))
		return &ubma_faclschs_fld;

	if (STR_EQ("ubma/faclschs/hd", path))
		return &ubma_faclschs_hd;

	if (STR_EQ("ubma/faclschs/bd", path))
		return &ubma_faclschs_bd;

	if (STR_EQ("ubma/faclschs/eld", path))
		return &ubma_faclschs_eld;

	if (STR_EQ("ubma/faclschs/td", path))
		return &ubma_faclschs_td;

	if (STR_EQ("ubma/faclschs/hssd", path))
		return &ubma_faclschs_hssd;

	if (STR_EQ("ubma/faclschs/psed", path))
		return &ubma_faclschs_psed;

	if (STR_EQ("ubma/faclschs/ild", path))
		return &ubma_faclschs_ild;

	if (STR_EQ("ubma/facsceg", path))
		return &ubma_facsceg;

	if (STR_EQ("ubma/facsceg/esd", path))
		return &ubma_facsceg_esd;

	if (STR_EQ("ubma/facsceg/ct", path))
		return &ubma_facsceg_ct;

	if (STR_EQ("ubma/facsceg/fsd", path))
		return &ubma_facsceg_fsd;

	if (STR_EQ("ubma/facsceg/msd", path))
		return &ubma_facsceg_msd;

	if (STR_EQ("ubma/facsct", path))
		return &ubma_facsct;

	if (STR_EQ("ubma/facsct/pd", path))
		return &ubma_facsct_pd;

	if (STR_EQ("ubma/facsct/ad", path))
		return &ubma_facsct_ad;

	if (STR_EQ("ubma/facsct/md", path))
		return &ubma_facsct_md;

	if (STR_EQ("ubma/facsct/gd", path))
		return &ubma_facsct_gd;

	if (STR_EQ("ubma/facsci", path))
		return &ubma_facsci;

	if (STR_EQ("ubma/facsci/ped", path))
		return &ubma_facsci_ped;

	if (STR_EQ("ubma/facsci/hd", path))
		return &ubma_facsci_hd;

	if (STR_EQ("ubma/facsci/ed", path))
		return &ubma_facsci_ed;

	if (STR_EQ("ubma/facsci/std", path))
		return &ubma_facsci_std;

	if (STR_EQ("ubma/facsci/csd", path))
		return &ubma_facsci_csd;

	if (STR_EQ("ubma/facsci/md", path))
		return &ubma_facsci_md;

	if (STR_EQ("ubma/facsci/tt", path))
		return &ubma_facsci_tt;

	if (STR_EQ("ubma/facsci/ced", path))
		return &ubma_facsci_ced;

	if (STR_EQ("ubma/facsci/d", path))
		return &ubma_facsci_d;

	if (STR_EQ("ubma/facsci/med", path))
		return &ubma_facsci_med;

	if (STR_EQ("ua2aks", path))
		return &ua2aks;

	if (STR_EQ("ua2aks/fle", path))
		return &ua2aks_fle;

	if (STR_EQ("ua2aks/fle/dfr", path))
		return &ua2aks_fle_dfr;

	if (STR_EQ("ua2aks/fle/dsgi", path))
		return &ua2aks_fle_dsgi;

	if (STR_EQ("ua2aks/fle/den", path))
		return &ua2aks_fle_den;

	if (STR_EQ("ua2aks/it", path))
		return &ua2aks_it;

	if (STR_EQ("ua2aks/ia", path))
		return &ua2aks_ia;

	if (STR_EQ("ua2aks/fss", path))
		return &ua2aks_fss;

	if (STR_EQ("ua2aks/fss/dedu", path))
		return &ua2aks_fss_dedu;

	if (STR_EQ("ua2aks/fss/dpsy", path))
		return &ua2aks_fss_dpsy;

	if (STR_EQ("ua2aks/fss/dst", path))
		return &ua2aks_fss_dst;

	if (STR_EQ("ua2aks/fss/dsocio", path))
		return &ua2aks_fss_dsocio;

	if (STR_EQ("ua2aks/fsh", path))
		return &ua2aks_fsh;

	if (STR_EQ("ua2aks/fsh/dh", path))
		return &ua2aks_fsh_dh;

	if (STR_EQ("ua2aks/fsh/dph", path))
		return &ua2aks_fsh_dph;

	if (STR_EQ("ua2aks/fsh/dld", path))
		return &ua2aks_fsh_dld;

	if (STR_EQ("ua2aks/falaol", path))
		return &ua2aks_falaol;

	if (STR_EQ("ua2aks/falaol/dts", path))
		return &ua2aks_falaol_dts;

	if (STR_EQ("ua2aks/falaol/dart", path))
		return &ua2aks_falaol_dart;

	if (STR_EQ("ua2aks/falaol/dtrl", path))
		return &ua2aks_falaol_dtrl;

	if (STR_EQ("ua2aks/falaol/dala", path))
		return &ua2aks_falaol_dala;

	return NULL;
}

#endif
