package HpcBetweenness;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author reecedevenney
 */
import HpcBetweenness.HpcBetweenness;
import org.gephi.statistics.spi.Statistics;
import org.gephi.statistics.spi.StatisticsBuilder;
import org.openide.util.lookup.ServiceProvider;

/**
 *
 * @author reecedevenney
 */
@ServiceProvider(service = StatisticsBuilder.class)
public class HpcBetweennessBuilder implements StatisticsBuilder {

    @Override
    public String getName() {
        return "HpcBetweenness";
    }

    @Override
    public Statistics getStatistics() {
        return new HpcBetweenness();
    }

    @Override
    public Class<? extends Statistics> getStatisticsClass() {
        return HpcBetweenness.class;
    }
}
