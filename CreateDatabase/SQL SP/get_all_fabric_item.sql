CREATE DEFINER=`root`@`localhost` PROCEDURE `get_all_fabric_item`()
BEGIN
	SELECT * FROM FabricItems;
END