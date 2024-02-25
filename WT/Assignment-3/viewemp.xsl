<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html"/>
  <xsl:template match="/">
    <html>
    <style>
    h2 {
        text-align: center;
        margin: 20px auto;
    }

    table {
    border-collapse: collapse;
    margin: auto;   
    width: 50%;
    }

    th, td {
    padding: 5px 10px;
    text-align: left;
    border-bottom: 1px solid #ddd;
    }

    th {
    background-color: #8cb8ff;
    border-top: 1px solid #ddd;
    }
    </style>
      <body>
        <h2>Employee Information</h2>
        <table >
          <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Position</th>
            <th>Department</th>
            <th>Salary</th>
          </tr>
          <xsl:apply-templates select="employees/employee"/>
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="employee">
    <tr>
      <td><xsl:value-of select="id"/></td>
      <td><xsl:value-of select="name"/></td>
      <td><xsl:value-of select="position"/></td>
      <td><xsl:value-of select="department"/></td>
      <td><xsl:value-of select="salary"/></td>
    </tr>
  </xsl:template>
</xsl:stylesheet>