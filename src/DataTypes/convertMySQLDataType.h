#pragma once

#include <string>
#include <Core/MultiEnum.h>
#include <Parsers/IAST.h>
#include "IDataType.h"

namespace DB
{
enum class MySQLDataTypesSupport;

/// Convert data type to query. for example
/// DataTypeUInt8 -> ASTIdentifier(UInt8)
/// DataTypeNullable(DataTypeUInt8) -> ASTFunction(ASTIdentifier(UInt8))
ASTPtr dataTypeConvertToQuery(const DataTypePtr & data_type);

/// Convert MySQL type to ClickHouse data type.
DataTypePtr convertMySQLDataType(MultiEnum<MySQLDataTypesSupport> type_support, const std::string & mysql_data_type, bool is_nullable, bool is_unsigned, size_t length, size_t precision, size_t scale);

}
