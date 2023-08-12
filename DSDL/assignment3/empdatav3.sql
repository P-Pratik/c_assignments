-- MySQL dump 10.13  Distrib 8.0.33, for Linux (x86_64)
--
-- Host: localhost    Database: emp_rec59
-- ------------------------------------------------------
-- Server version	8.0.33-0ubuntu0.20.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `dependant`
--

DROP TABLE IF EXISTS `dependant`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `dependant` (
  `emp_id` int DEFAULT NULL,
  `name_of_dependant` varchar(255) DEFAULT NULL,
  `age` int DEFAULT NULL,
  `relation` varchar(255) DEFAULT NULL,
  KEY `emp_id` (`emp_id`),
  CONSTRAINT `dependant_ibfk_1` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dependant`
--

LOCK TABLES `dependant` WRITE;
/*!40000 ALTER TABLE `dependant` DISABLE KEYS */;
INSERT INTO `dependant` VALUES (101,'Avni Patil',40,'Manager'),(102,'Meera Deshmukh',45,'Client'),(103,'Rahul Joshi',35,'Peer'),(104,'Pooja Pawar',33,'Peer'),(105,'Alok Bhosale',50,'Manager'),(106,'Aanya Patil',25,'Client'),(107,'Shaurya Chavan Jr.',28,'Client'),(108,'Anika Kulkarni',24,'Peer'),(109,'Aarav Ghosh Jr.',27,'Peer'),(110,'Prisha Gavade',26,'Client');
/*!40000 ALTER TABLE `dependant` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dept`
--

DROP TABLE IF EXISTS `dept`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `dept` (
  `dept_no` int NOT NULL,
  `name` varchar(255) DEFAULT NULL,
  `location` varchar(255) DEFAULT NULL,
  `manager_emp_id` int DEFAULT NULL,
  PRIMARY KEY (`dept_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dept`
--

LOCK TABLES `dept` WRITE;
/*!40000 ALTER TABLE `dept` DISABLE KEYS */;
INSERT INTO `dept` VALUES (10,'Development','Building 1',101),(11,'Testing','Building 2',102),(12,'Planning','Building 3',103),(13,'Service','Main Building',104),(14,'Administration','Building 2',105),(15,'Computer','Main Building',106);
/*!40000 ALTER TABLE `dept` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee` (
  `emp_name` varchar(255) DEFAULT NULL,
  `emp_id` int NOT NULL,
  `address` varchar(1000) DEFAULT NULL,
  `city` varchar(255) DEFAULT NULL,
  `dob` date DEFAULT NULL,
  `date_of_joining` date DEFAULT NULL,
  `gender` char(1) DEFAULT NULL,
  `salary` int DEFAULT NULL,
  `dept_no` int DEFAULT NULL,
  `mobile_number` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`emp_id`),
  KEY `dept_no` (`dept_no`),
  CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`dept_no`) REFERENCES `dept` (`dept_no`),
  CONSTRAINT `employee_chk_1` CHECK ((`gender` in (_utf8mb4'M',_utf8mb4'F',_utf8mb4'O')))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
INSERT INTO `employee` VALUES ('Aryan Patel',101,'123 Main St, Mumbai','Mumbai','1985-02-20','2010-05-15','M',80000,10,'+91-9909010327'),('Diya Deshmukh',102,'456 Elm Rd, Pune','Pune','1988-07-10','2013-09-25','F',75000,11,'+91-8909019327'),('Vivaan Joshi',103,'789 Oak Ave, Nashik','Nashik','1990-11-05','2016-03-12','M',90000,12,'+91-9901930320'),('Aanya Pawar',104,'567 Maple Ln, Nagpur','Nagpur','1992-04-30','2017-08-22','F',70000,13,'+91-9901930321'),('Reyansh Bhosale',105,'345 Pine Rd, Aurangabad','Aurangabad','1989-09-15','2012-01-18','M',85000,14,'+91-9901930322'),('Avni Patil',106,'123 Main St, Mumbai','Mumbai','1991-06-25','2015-06-30','F',82000,10,'+91-9901930323'),('Shaurya Chavan',107,'234 Birch Rd, Pune','Pune','1993-03-12','2018-11-10','M',78000,11,'+91-9901930324'),('Anika Kulkarni',108,'567 Elm Ave, Nashik','Nashik','1987-08-08','2011-09-05','F',76000,12,'+91-9901930325'),('Aarav Ghosh',109,'789 Oak St, Nagpur','Nagpur','1995-01-05','2019-07-20','M',92000,13,'+91-9901930326'),('Prisha Gavade',110,'123 Cedar Rd, Aurangabad','Aurangabad','1994-12-01','2014-05-28','F',80000,14,'+91-9901930327'),('Zara Khan',111,'789 Willow Rd, Delhi','Delhi','1994-08-12','2020-03-15','F',85000,15,'+91-9901930328'),('Rohan Sharma',112,'567 Birch St, Mumbai','Mumbai','1995-01-02','2021-06-10','M',78000,15,'+91-9901930329'),('Neha Gupta',113,'123 Elm Ave, Bangalore','Bangalore','1993-11-18','2019-12-05','F',90000,15,'+91-9901930330'),('Arjun Patel',114,'456 Oak Rd, Hyderabad','Hyderabad','1995-06-30','2020-09-20','M',80000,15,'+91-9901930331');
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `project`
--

DROP TABLE IF EXISTS `project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `project` (
  `project_id` int NOT NULL,
  `title` varchar(255) DEFAULT NULL,
  `city` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`project_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `project`
--

LOCK TABLES `project` WRITE;
/*!40000 ALTER TABLE `project` DISABLE KEYS */;
INSERT INTO `project` VALUES (1000,'Online Banking System','Mumbai'),(1002,'Enterprise Resource Planning','Nashik'),(1003,'E-commerce Platform Upgrade','Nagpur'),(1004,'Sales Management System','Aurangabad'),(1005,'Digital Payment Integration','Mumbai'),(1006,'Data Analysis Tool Development','Pune'),(1007,'Supply Chain Optimization','Nashik'),(1008,'Inventory Management System','Nagpur'),(1009,'Customer Relationship Management','Aurangabad');
/*!40000 ALTER TABLE `project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `works`
--

DROP TABLE IF EXISTS `works`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `works` (
  `emp_id` int DEFAULT NULL,
  `project_id` int DEFAULT NULL,
  `total_hrs_worked` int DEFAULT NULL,
  KEY `emp_id` (`emp_id`),
  KEY `project_id` (`project_id`),
  CONSTRAINT `works_ibfk_1` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`),
  CONSTRAINT `works_ibfk_2` FOREIGN KEY (`project_id`) REFERENCES `project` (`project_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `works`
--

LOCK TABLES `works` WRITE;
/*!40000 ALTER TABLE `works` DISABLE KEYS */;
INSERT INTO `works` VALUES (101,1000,120),(102,1002,90),(103,1002,140),(104,1003,80),(105,1004,110),(106,1005,100),(107,1006,70),(108,1007,130),(103,1008,95),(110,1009,115);
/*!40000 ALTER TABLE `works` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-08-12 12:16:21
