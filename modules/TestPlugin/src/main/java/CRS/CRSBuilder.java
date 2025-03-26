/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CRS;

import org.gephi.statistics.spi.Statistics;
import org.gephi.statistics.spi.StatisticsBuilder;
import org.openide.util.lookup.ServiceProvider;

/**
 *
 * @author reecedevenney
 */
@ServiceProvider(service = StatisticsBuilder.class)
public class CRSBuilder implements StatisticsBuilder {

    @Override
    public String getName() {
        return "CRS";
    }

    @Override
    public Statistics getStatistics() {
        return new CRS();
    }

    @Override
    public Class<? extends Statistics> getStatisticsClass() {
        return CRS.class;
    }
}

