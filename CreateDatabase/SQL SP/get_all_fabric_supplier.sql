CREATE DEFINER=`root`@`localhost` PROCEDURE `get_all_fabric_supplier`()
BEGIN
SELECT * FROM FabricSuppliers;
END